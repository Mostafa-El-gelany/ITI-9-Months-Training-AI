import pandas as pd

class ReportGenerator:
    def __init__(self):
        self.CLR = {
            "blue": "\033[94m", "green": "\033[92m", 
            "warning": "\033[93m", "fail": "\033[91m", "bold": "\033[1m", "end": "\033[0m"
        }

    def generate_report(self, df):
        """Main orchestrator function."""
        print(f"{self.CLR['bold']}{self.CLR['blue']}🚀 Starting High-Risk Analysis...{self.CLR['end']}")
        
        flagged_tx = self._filter_transactions(df)
        flagged_users = self._profile_users(flagged_tx)
        flagged_users = self._apply_risk_levels(flagged_users)
        
        self._save_csv_files(flagged_tx, flagged_users)
        self._generate_fancy_txt(flagged_tx, flagged_users)
        
        print(f"{self.CLR['green']}✨ All reports generated successfully!{self.CLR['end']}")
        return flagged_users

    def _filter_transactions(self, df):
        """Filters the main dataframe for suspicious activities."""
        return df[df['transactionRisk'].isin(['High', 'Critical'])].copy()

    def _profile_users(self, flagged_tx):
        """Identifies users and determines if they are senders, receivers, or both."""
        senders = flagged_tx[flagged_tx['senderRisk'].isin(['High', 'Critical'])][['nameOrig', 'senderScore', 'amount']].copy()
        senders.columns = ['UserID', 'RiskScore', 'Amount']
        senders['UserType'] = 'sender'

        receivers = flagged_tx[flagged_tx['receiverRisk'].isin(['High', 'Critical'])][['nameDest', 'receiverScore', 'amount']].copy()
        receivers.columns = ['UserID', 'RiskScore', 'Amount']
        receivers['UserType'] = 'receiver'

        combined = pd.concat([senders, receivers], ignore_index=True)

        def get_user_type(types):
            unique_types = set(types)
            if len(unique_types) > 1: return 'both 🔄'
            return 'sender 📤' if 'sender' in unique_types else 'receiver 📥'

        user_profiles = combined.groupby('UserID').agg({
            'RiskScore': 'max',
            'Amount': ['sum', 'count'],
            'UserType': get_user_type
        }).reset_index()

        user_profiles.columns = ['UserID', 'RiskScore', 'TotalVolume', 'TxCount', 'UserType']
        return user_profiles

    def _apply_risk_levels(self, user_df):
        """Calculates final RiskLevel based on numerical RiskScore."""
        user_df['RiskLevel'] = 'Low'
        user_df.loc[user_df['RiskScore'].abs() > 1, 'RiskLevel'] = 'Medium 🟡'
        user_df.loc[user_df['RiskScore'].abs() > 3, 'RiskLevel'] = 'High 🟠'
        user_df.loc[user_df['RiskScore'].abs() > 9, 'RiskLevel'] = 'Critical 🔴'
        return user_df

    def _save_csv_files(self, tx_df, user_df):
        tx_df.to_csv('flagged_transactions_report.csv', index=False)
        user_df.to_csv('flagged_users_report.csv', index=False)

    def _generate_fancy_txt(self, tx_df, user_df):
        """Writes the executive summary with User Type totals and percentages."""
        total_users = len(user_df)
        type_counts = user_df['UserType'].value_counts()
        
        # Calculate counts
        c_sender = type_counts.get('sender 📤', 0)
        c_receiver = type_counts.get('receiver 📥', 0)
        c_both = type_counts.get('both 🔄', 0)

        # Calculate percentages
        p_sender = (c_sender / total_users * 100) if total_users > 0 else 0
        p_receiver = (c_receiver / total_users * 100) if total_users > 0 else 0
        p_both = (c_both / total_users * 100) if total_users > 0 else 0

        with open("executive_summary.txt", "w", encoding="utf-8") as f:
            f.write("💎" + "—" * 50 + "💎\n")
            f.write("  FINANCIAL INTELLIGENCE REPORT: HIGH-RISK ENTITIES\n")
            f.write("💎" + "—" * 50 + "💎\n\n")

            # Section 1: Vital Stats
            f.write("📈 OVERALL MARKET VITAL SIGNS\n")
            f.write(f"  💰 Total Value at Risk:   ${tx_df['amount'].sum():,.2f}\n")
            f.write(f"  🚨 Critical Incidents:    {len(tx_df[tx_df['transactionRisk']=='Critical'])}\n")
            f.write(f"  👥 Total Unique Entities:  {total_users}\n\n")

            # Section 2: Entity Role Distribution (DETAILED)
            f.write("🎭 ENTITY ROLE DISTRIBUTION\n")
            f.write(f"  📤 Pure Senders:   {c_sender:<4} entities ({p_sender:>5.1f}%)\n")
            f.write(f"  📥 Pure Receivers: {c_receiver:<4} entities ({p_receiver:>5.1f}%)\n")
            f.write(f"  🔄 Dual-Role:      {c_both:<4} entities ({p_both:>5.1f}%)\n")


            # Section 3: TOP 5 SENDERS
            f.write("📤 TOP 5 HIGHEST RISK SENDERS\n")
            f.write(f"{'Rank':<5} {'UserID':<15} {'Score':<8} {'Volume':<12} {'Risk'}\n")
            f.write("-" * 65 + "\n")
            top_senders = user_df[user_df['UserType'].str.contains('sender|both')].nlargest(5, 'RiskScore')
            for i, (_, row) in enumerate(top_senders.iterrows(), 1):
                f.write(f"#{i:<4} {row['UserID']:<15} {row['RiskScore']:<8.2f} ${row['TotalVolume']:<11,.0f} {row['RiskLevel']}\n")
            f.write("\n")

            # Section 4: TOP 5 RECEIVERS
            f.write("📥 TOP 5 HIGHEST RISK RECEIVERS\n")
            f.write(f"{'Rank':<5} {'UserID':<15} {'Score':<8} {'Volume':<12} {'Risk'}\n")
            f.write("-" * 65 + "\n")
            top_receivers = user_df[user_df['UserType'].str.contains('receiver|both')].nlargest(5, 'RiskScore')
            for i, (_, row) in enumerate(top_receivers.iterrows(), 1):
                f.write(f"#{i:<4} {row['UserID']:<15} {row['RiskScore']:<8.2f} ${row['TotalVolume']:<11,.0f} {row['RiskLevel']}\n")
            f.write("\n")

            # Section 5: Risk Volume Distribution
            f.write("📊 RISK DISTRIBUTION BY VOLUME\n")
            dist = user_df.groupby('RiskLevel')['TotalVolume'].sum()
            total_vol = dist.sum()
            for level, val in dist.items():
                percentage = (val / total_vol) * 100 if total_vol > 0 else 0
                bar = "■" * int(percentage / 5)
                f.write(f"  {level:<12} | {bar:<20} | {percentage:>5.1f}%\n")

            f.write(f"END OF CONFIDENTIAL DISCLOSURE")
    def display_summary(self):
        with open("executive_summary.txt", "r", encoding="utf-8") as f:
            summary = f.read()
            print(summary)