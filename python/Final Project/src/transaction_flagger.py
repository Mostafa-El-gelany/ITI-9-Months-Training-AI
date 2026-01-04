class TransactionFlagger:
    def __init__(self):
        self.data = None
    def flag(self, df):
        # 1. Start with the default
        df['transactionRisk'] = 'Low'
        # 2. Update based on thresholds
        df.loc[df['transactionScore'].abs() > 1, 'transactionRisk'] = 'Medium'
        df.loc[df['transactionScore'].abs() > 3, 'transactionRisk'] = 'High'
        df.loc[df['transactionScore'].abs() > 9, 'transactionRisk'] = 'Critical'
        df['senderRisk']='Low'
        df.loc[df['senderScore'].abs() > 1, 'senderRisk'] = 'Medium'
        df.loc[df['senderScore'].abs() > 3, 'senderRisk'] = 'High'
        df.loc[df['senderScore'].abs() > 9, 'senderRisk'] = 'Critical'
        df['receiverRisk']='Low'
        df.loc[df['receiverScore'].abs() > 1, 'receiverRisk'] = 'Medium'
        df.loc[df['receiverScore'].abs() > 3, 'receiverRisk'] = 'High'
        df.loc[df['receiverScore'].abs() > 9, 'receiverRisk'] = 'Critical'
        return df