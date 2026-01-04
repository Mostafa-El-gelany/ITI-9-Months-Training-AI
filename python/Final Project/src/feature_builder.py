import scipy as sp
class FeatureBuilder:
    def __init__(self):
        self.data = None

    def build_features(self, df):
        
        
        
        df['senderGap']=abs(abs(df.oldbalanceOrg - df.newbalanceOrig)-df.amount)
        df['receiverGap']=abs(abs(df.oldbalanceDest - df.newbalanceDest)-df.amount)
        df['day']=df['step']//24
        df.drop(['step'],axis=1,inplace=True)
        
        group=df.groupby(['nameOrig','day'])['amount']
        df['senderDailyTransactionSum']=group.transform('sum')
        df['senderDailyTransactionCount']=group.transform('count')
        
        group=df.groupby(['nameDest','day'])['amount']
        df['receiverDailyTransactionSum']=group.transform('sum')
        df['receiverDailyTransactionCount']=group.transform('count')
        
        group=df.groupby('nameOrig')['amount']
        df['senderMaxAmount'] = group.transform('max')
        df['senderAverageAmount'] = group.transform('mean')
        df['senderTotalAmount'] = group.transform('sum')
        df['senderTransactionsCount'] = group.transform('count')
        
        group=df.groupby('nameDest')['amount']
        df['receiverMaxAmount'] = group.transform('max')
        df['receiverAverageAmount'] = group.transform('mean')
        df['receiverTotalAmount'] = group.transform('sum')
        df['receiverTransactionsCount'] = group.transform('count')
        return df