import msvcrt
import os
import transaction_cleaner
import feature_builder
import risk_scorer
import transaction_flagger
import data_manager
import report_generator

# ANSI Color Codes
class Colors:
    HEADER = '\033[95m'
    BLUE = '\033[94m'
    CYAN = '\033[96m'
    GREEN = '\033[92m'
    YELLOW = '\033[93m'
    RED = '\033[91m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'
    ENDC = '\033[0m'

class ConsoleApp:
    def __init__(self):
        self.df = None
        self.num = 0
        # Initialize logic modules once to save memory/time
        self.tc = transaction_cleaner.TransactionCleaner()
        self.fb = feature_builder.FeatureBuilder()
        self.rs = risk_scorer.RiskScorer()
        self.tf = transaction_flagger.TransactionFlagger()
        self.dm = data_manager.DataManager()
        self.rg = report_generator.ReportGenerator()

        # Menu configuration: (Label, Emoji)
        self.menu_items = [
            ("Load dataset", "📥"),
            ("Clean and validate data", "🧹"),
            ("Build features", "⚙️ "),
            ("Score customers", "📊"),
            ("Flag suspicious transactions", "🚩"),
            ("Export reports", "📁"),
            ("Display summary in console", "🖥️ "),
            ("Exit application", "❌")
        ]

    def run(self):
        ptr = 0
        while True:
            self.display(ptr)
            ptr = self.manage_keys(ptr)

    def manage_flow(self, ptr):
        """Validates if the user is allowed to proceed to the next step."""
        if ptr > self.num:
            print(f"\n{Colors.RED}⚠️  Error: Sequence violation.{Colors.ENDC}")
            print(f"{Colors.YELLOW}Please complete step {self.num + 1} first.{Colors.ENDC}")
            msvcrt.getch()
            return 0
        if ptr == 6:
            return 1
        if ptr < self.num:
            # Don't allow re-running previous steps.
            print(f"\n{Colors.RED}⚠️  Error: Step already completed.{Colors.ENDC}")
            print(f"{Colors.YELLOW}Please proceed to the next step.{Colors.ENDC}")
            msvcrt.getch()
            return 0
        
        return 1

    def manage_keys(self, ptr):
        key = msvcrt.getch()
        
        # Handle Arrow Keys (Windows usually sends b'\xe0' then the direction)
        if key == b'\xe0': 
            key = msvcrt.getch()
            if key == b'H': ptr = (ptr - 1) % len(self.menu_items) # Up
            elif key == b'P': ptr = (ptr + 1) % len(self.menu_items) # Down
            return ptr

        if key == b'\r':  # Enter Key
            if ptr == 7: exit()
            
            if self.manage_flow(ptr):
                self.execute_step(ptr)
            return ptr
        
        return ptr

    def execute_step(self, ptr):
        """Logic execution for each menu item."""
        print(f"\n{Colors.BOLD}{Colors.CYAN}🚀 Executing: {self.menu_items[ptr][0]}...{Colors.ENDC}")
        
        try:
            if ptr == 0:
                self.df = self.dm.load_data()
            elif ptr == 1:
                self.df = self.tc.clean_data(self.df)
            elif ptr == 2:
                self.df = self.fb.build_features(self.df)
            elif ptr == 3:
                self.df = self.rs.score(self.df)
            elif ptr == 4:
                self.df = self.tf.flag(self.df)
            elif ptr == 5:
                self.rg.generate_report(self.df)
            elif ptr == 6:
                self.rg.display_summary()

            # Increment progress if we just finished the 'next' logical step
            if ptr == self.num:
                self.num += 1

            print(f"\n{Colors.GREEN}✅ Success! Press any key to continue...{Colors.ENDC}")
        except Exception as e:
            print(f"\n{Colors.RED}❌ An error occurred: {e}{Colors.ENDC}")
        
        msvcrt.getch()

    def display(self, ptr):
        os.system("cls")
        print(f"{Colors.HEADER}{Colors.BOLD}══════════════════════════════════════════")
        print(f"   🛡️  FRAUD DETECTION SYSTEM DASHBOARD   ")
        print(f"══════════════════════════════════════════{Colors.ENDC}\n")

        for i, (label, emoji) in enumerate(self.menu_items):
            # Show completed items with a checkmark
            status_icon = "✅" if i < self.num else "  "
            if i == 7: status_icon = "  " # Exit doesn't need a check

            if i == ptr:
                # Highlighted selection
                print(f"{Colors.YELLOW}  👉 {Colors.BOLD}{Colors.BLUE}[ {emoji} {label.upper()} ]{Colors.ENDC}")
            else:
                # Regular items
                # Dim the items that aren't 'unlocked' yet
                if i > self.num and i != 7:
                    print(f"     {status_icon} {Colors.RED}🔒 {label}")
                else:
                    print(f"     {status_icon} {emoji} {label}")
        
        print(f"\n{Colors.CYAN}💡 Use Arrow Keys to navigate and Enter to select.{Colors.ENDC}")
        print(f"{Colors.HEADER}──────────────────────────────────────────{Colors.ENDC}")

if __name__ == "__main__":
    app = ConsoleApp()
    app.run()