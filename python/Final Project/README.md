
# Fraud Detection System Dashboard 🛡️

This professional terminal-based application is designed to process financial transaction logs, perform advanced feature engineering, calculate risk scores using statistical methods, and generate comprehensive intelligence reports.


## 🛠️ Project Architecture
The system is built as a modular pipeline where each step must be completed sequentially to ensure data integrity.

Core Modules
- data_manager.py: Handles initial data loading; it shuffles the dataset and takes a 100,000-row sample to optimize performance.

- transaction_cleaner.py: Pre-processes data by removing known fraud cases, dropping redundant columns like isFlaggedFraud and isFraud, and removing duplicates.

- feature_builder.py: Engineering engine that calculates balance gaps, extracts time features, and computes rolling daily sums/counts for both senders and receivers.

- risk_scorer.py: Performs statistical analysis by calculating Z-Scores for various behaviors (amount, transaction gaps, daily volume) to identify outliers.

- transaction_flagger.py: Maps numerical risk scores to categorical levels: Low, Medium, High, and Critical based on specific score thresholds.

- report_generator.py: Orchestrates the final output by profiling users, saving CSV files, and generating a fancy executive summary text file.
## 🚀 Getting Started
Prerequisites
- Python 3.x

- Required Libraries: pandas, numpy, scipy

### Installation

Ensure your transaction dataset (CSV) is located at the path specified in data_manager.py.
## 🖥️ Dashboard Interface
The application uses a strict State-Machine Workflow managed through a console interface.

Workflow Rules
- Sequential Execution: You cannot skip steps; for example, you cannot score customers until features are built.

- Immutability: Once a step is successfully completed, it is locked to prevent re-processing and data inconsistency.

- Navigation: Use Arrow Keys to navigate and Enter to select the current available step.
## 📊 Output Reports
- Upon completion of the Export Reports step, the system generates several files:

- flagged_transactions_report.csv: Contains every transaction marked as High or Critical risk.

- flagged_users_report.csv: A profile of unique entities including their total volume and risk level.

- executive_summary.txt: A visual summary including vital signs, role distribution, and top-risk entities.
## 💎 Key Features
- Fancy Console UI: Uses ANSI escape codes for colors and emojis to provide a modern terminal experience.

- Behavioral Profiling: Distinguishes between pure senders, pure receivers, and "Dual-Role" entities who both send and receive high-risk funds.

- Z-Score Analysis: Scientifically identifies suspicious activity by measuring how many standard deviations a transaction is from the mean.