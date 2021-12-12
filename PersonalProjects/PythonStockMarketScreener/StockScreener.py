import pandas as pd
import numpy as np
import yfinance as yf
import datetime as dt
from pandas_datareader import data as pdr
from tkinter.filedialog import askopenfilename
import os
from pandas import ExcelWriter



yf.pdr_override()
start=dt.datetime(2019,1,1)
now=dt.datetime.now()

#filePath=r"C:\Users\zimme\Documents\Python\stocklist.xlsx"

root=Tk()
ftypes = [(".xlsm","*.xlsx",".xls")]
tt1="Title"
dir1 = 'C:\\'
filePath=askopenfilename(filetypes = ftypes, initialdir = dir1, title = tt1)


stocklist=pd.read_excel(filePath)
stocklist=stocklist.head()

exportList=pd.DataFrame(columns=['Stock', "RS_Rating", "50 Day MA", "150 Day MA", "200 Day MA", "52 Week Low", "52 Week High"])

for i in stocklist.index:
	stock=str(stocklist["Symbol"][i])
	RS_Rating=stocklist["RS Rating"][i]

	try:
		df = pdr.get_data_yahoo(stock,start,now)

		smasUsed=[50,150,200]
		for x in smasUsed:
			sma=x
			df["SMA_"+str(sma)]=round(df.iloc[:,4].rolling(window=sma).mean(),2)

		currentClose=df["Adj Close"][-1]
		moving_average_50=df["SMA_50"][-1]
		moving_average_150=df["SMA_150"][-1]
		moving_average_200=df["SMA_200"][-1]
		low_of_52week=min(df["Adj Close"][-260:])
		high_of_52week=max(df["Adj Close"][-260:])

		try:
			moving_average_200_20past=df["SMA_200"][-20]

		except Exception:

			moving_average_200_20past=0


		print("Checking "+stock+".....")


		if(currentClose>moving_average_150 and currentClose>moving_average_200):
			cond_1=True
		else:
			cond_1=False

		if(moving_average_150>moving_average_200):
			cond_2=True
		else:
			cond_2=False

		if(moving_average_200>moving_average_200_20past):
			cond_3=True
		else:
			cond_3=False

		if(moving_average_50>moving_average_150 and moving_average_50>moving_average_200):
			cond_4=True
		else:
			cond_4=False

		if(currentClose>moving_average_50):
			cond_5=True
		else:
			cond_5=False

		if(currentClose>(1.3*low_of_52week)):
			cond_6=True
		else:
			cond_6=False

		if(currentClose>=(.75*high_of_52week)):
			cond_7=True
		else:
			cond_7=False

		if(RS_Rating>70):

			cond_8=True
		else:
			cond_8=False

		if(cond_1 and cond_2 and cond_3 and cond_4 and cond_5 and cond_6 and cond_7 and cond_8):
			exportList = exportList.append({'Stock': stock,"RS_Rating": RS_Rating,"50 Day MA": moving_average_50,"150 Day MA": moving_average_150, "200 Day MA": moving_average_200, "52 Week Low": low_of_52week, "52 Week High":high_of_52week,})
	except Exception:
		print("No data on "+stock)

print(exportList)


newFile=os.path.dirname(filePath)+"/ScreenOutput.xlsx"

writer=ExcelWriter(newFile)
exportList.to_excel(writer,"Sheet1")
writer.save()