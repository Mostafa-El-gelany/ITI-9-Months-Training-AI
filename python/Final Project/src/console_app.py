import msvcrt
import os
from src.transaction_cleaner import TransactionCleaner
from src.feature_builder import FeatureBuilder
from src.risk_scorer import RiskScorer
from src.transaction_flagger import TransactionFlagger
from src.data_manager import DataManager
from src.report_generator import ReportGenerator
from src.colors import Colors

class ConsoleApp:
    def __init__(self):
        self.df = None
        self.num = 0

        self.tc = TransactionCleaner()
        self.fb = FeatureBuilder()
        self.rs = RiskScorer()
        self.tf = TransactionFlagger()
        self.dm = DataManager()
        self.rg = ReportGenerator()
        self.c = Colors()


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
        if ptr > self.num:
            print(f"\n{self.c.RED}⚠️  Error: Sequence violation.{self.c.ENDC}")
            print(f"{self.c.YELLOW}Please complete step {self.num + 1} first.{self.c.ENDC}")
            msvcrt.getch()
            return 0
        
        if ptr == 6:
            return 1
        
        if ptr < self.num:
            print(f"\n{self.c.RED}⚠️  Error: Step already completed.{self.c.ENDC}")
            print(f"{self.c.YELLOW}Please proceed to the next step.{self.c.ENDC}")
            msvcrt.getch()
            return 0
        
        return 1

    def manage_keys(self, ptr):
        key = msvcrt.getch()
        
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

        print(f"\n{self.c.BOLD}{self.c.CYAN}🚀 Executing: {self.menu_items[ptr][0]}...{self.c.ENDC}")
        
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

            if ptr == self.num:
                self.num += 1

            print(f"\n{self.c.GREEN}✅ Success! Press any key to continue...{self.c.ENDC}")
        except Exception as e:
            print(f"\n{self.c.RED}❌ An error occurred: {e}{self.c.ENDC}")
        
        msvcrt.getch()

    def display(self, ptr):
        os.system("cls")
        print(f"{self.c.HEADER}{self.c.BOLD}══════════════════════════════════════════")
        print(f"   🛡️  FRAUD DETECTION SYSTEM DASHBOARD   ")
        print(f"══════════════════════════════════════════{self.c.ENDC}\n")

        for i, (label, emoji) in enumerate(self.menu_items):

            status_icon = "✅" if i < self.num else "  "
            if i == 7: status_icon = "  " # Exit doesn't need a check

            if i == ptr:
                print(f"{self.c.YELLOW}  👉 {self.c.BOLD}{self.c.BLUE}[ {emoji} {label.upper()} ]{self.c.ENDC}")
            else:

                if i > self.num and i != 7:
                    print(f"     {status_icon} {self.c.RED}🔒 {label}{self.c.ENDC}")
                else:
                    print(f"     {status_icon} {emoji} {label}")
        
        print(f"\n{self.c.CYAN}💡 Use Arrow Keys to navigate and Enter to select.{self.c.ENDC}")
        print(f"{self.c.HEADER}──────────────────────────────────────────{self.c.ENDC}")
