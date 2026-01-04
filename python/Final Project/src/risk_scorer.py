import scipy as sp
class RiskScorer:
    def __init__(self):
        self.data=None
    def score(self, df):
        df['senderGapScore']=sp.stats.zscore(df['senderGap'])
        df['receiverGapScore']=sp.stats.zscore(df['receiverGap'])
        df['amountScore']=sp.stats.zscore(df['amount'])
        df['senderDailyTransactionSumScore']=sp.stats.zscore(df['senderDailyTransactionSum'])
        df['senderDailyTransactionCountScore']=sp.stats.zscore(df['senderDailyTransactionCount'])
        df['receiverDailyTransactionSumScore']=sp.stats.zscore(df['receiverDailyTransactionSum'])
        df['receiverDailyTransactionCountScore']=sp.stats.zscore(df['receiverDailyTransactionCount'])
        df['transactionScore']=df[['senderGapScore','receiverGapScore','amountScore','senderDailyTransactionSumScore','senderDailyTransactionCountScore','receiverDailyTransactionSumScore','receiverDailyTransactionCountScore']].max(axis=1)
        df['senderScore'] = df.groupby('nameOrig')[['senderGapScore','senderDailyTransactionSumScore','senderDailyTransactionCountScore','amountScore']].transform('max').max(axis=1)
        df['receiverScore'] = df.groupby('nameDest')[['receiverGapScore','receiverDailyTransactionSumScore','receiverDailyTransactionCountScore','amountScore']].transform('max').max(axis=1)
        return df