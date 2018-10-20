import csv
import sys
from random import shuffle
import matplotlib.pyplot as plt

#Global values and parameters
learningRate=.02
MAX_ITERATIONS=100
totalAttr=0
totalFields=0
totalSets=0
no_TrainSets=0
no_TestSets=0
setSize=0
fold_Accuracy = []
each_fold_Accuracy = []

#Parse dataset
def parseCSV(filename):

	fields = []
	rows = []
	global totalAttr,totalFields,totalSets,no_TrainSets,no_TestSets,setSize

	with open(filename, 'r') as csvfile:
		csvreader = csv.reader(csvfile)
		fields = next(csvreader)
		nameFlag=1
		className=""
		for row in csvreader:
			if(nameFlag):
				className=row[totalFields-1]
				nameFlag=0
			if row[totalFields-1]==className:
				row[totalFields-1]=1
			else:
				row[totalFields-1]=0
			rows.append(row)
	
	totalFields=len(fields)
	totalAttr=totalFields-1
	totalSets=len(rows)
	setSize=(totalSets)//10
	no_TrainSets=9*setSize
	no_TestSets=totalSets-no_TrainSets
	return fields,rows

#10 fold cross validation
def trainAndCrossValidate(rows,weights,bias):
	kFold=0
	train_st=0
	net_precisionPos=net_precisionNeg=net_recallPos=net_recallNeg=0
	net_precisionPosCount=net_precisionNegCount=net_recallPosCount=net_recallNegCount=0
	net_accuracy=net_error=0

	while(kFold<10):

		print("Fold No.",kFold+1)
		print("Training model...")
		weights,bias=trainModel(rows,weights,bias,train_st)
		print("Testing model...")
		test_st=(train_st+no_TrainSets)%totalSets
		truePos,falsePos,trueNeg,falseNeg=testModel(rows,weights,bias,test_st)

		if((truePos+falsePos)!=0):
			precisionPos=(truePos)/(truePos+falsePos)
			net_precisionPos+=(precisionPos)
			net_precisionPosCount+=1
			print("Precision_Pos %=",precisionPos*100,end='\t')
		if((truePos+falseNeg)!=0):
			recallPos=(truePos)/(truePos+falseNeg)
			net_recallPos+=(recallPos)
			net_recallPosCount+=1
			print("Recall_Pos %=",recallPos*100)
		if((trueNeg+falseNeg)!=0):
			precisionNeg=(trueNeg)/(trueNeg+falseNeg)
			net_precisionNeg+=(precisionNeg)
			net_precisionNegCount+=1
			print("Precision_Neg %=",precisionNeg*100,end='\t')
		if((trueNeg+falsePos)!=0):
			recallNeg=(trueNeg)/(trueNeg+falsePos)
			net_recallNeg+=(recallNeg)
			net_recallNegCount+=1
			print("Recall_Neg %=",recallNeg*100)
		accuracy=((trueNeg+truePos)/(trueNeg+truePos+falseNeg+falsePos))
		net_accuracy+=accuracy
		print("Accuracy %=",accuracy*100)
		fold_Accuracy.append(accuracy*100)
		train_st=(train_st+setSize)%totalSets
		kFold+=1
		print("***************************************************")

	net_precisionPos/=net_precisionPosCount
	net_recallPos/=net_recallPosCount
	net_precisionNeg/=net_recallNegCount
	net_recallNeg/=net_recallNegCount
	net_accuracy/=10
	print("Average Recall_Pos %=",net_recallPos*100,"\nAverage Precision_Pos %=",net_precisionPos*100)
	print("Average Recall_Neg %=",net_recallNeg*100,"\nAverage Precision_Neg %=",net_precisionNeg*100)
	print("Average Accuracy %=",net_accuracy*100)

def testModel(rows,weights,bias,test_st):
	falsePos=truePos=falseNeg=trueNeg=posCount=negCount=0
	testNo=0
	test=test_st
	while testNo<no_TrainSets:
		predOp=predict(weights,bias,rows[test])
		correctOp=rows[test][totalFields-1]
		if(correctOp==0):
			negCount+=1
		else:
			posCount+=1
		if(predOp==correctOp):
			if(predOp==1):
				truePos+=1
			else:
				trueNeg+=1
		else:
			if(predOp==1):
				falsePos+=1
			else:
				falseNeg+=1
		testNo+=1
		test=(test+1)%totalSets

	return truePos,falsePos,trueNeg,falsePos

def correctWeights(weights,bias,data,opDiff):
	for attr in range(totalAttr):
		weights[attr]+=(learningRate*opDiff*float(data[attr]))
	bias+=(learningRate*opDiff)
	return weights,bias


#Train the single perceptron
def trainModel(rows,weights,bias,train_st):
	iterations=0
	totalErrors=1
	while(totalErrors>0 and iterations<MAX_ITERATIONS):
		weights,bias,totalErrors=trainModelOnce(rows,weights,bias,train_st)
		iterations+=1
	return weights,bias

#Single run of all datasets
def trainModelOnce(rows,weights,bias,train_st):
	totalErrors=0
	train=train_st
	trainNo=0
	while(trainNo<no_TrainSets):
		prediction=predict(weights,bias,rows[train])
		correctOp=rows[train][totalFields-1]
		opDiff=correctOp-prediction
		weights,bias=correctWeights(weights,bias,rows[train],opDiff)
		if(opDiff!=0):
			totalErrors+=1
		train=(train+1)%totalSets
		trainNo+=1
	return weights,bias,totalErrors

#Given single tuple predict output
def predict(weights,bias,data):
	weightInp=0
	for attr in range(totalAttr):
		weightInp+=(float(data[attr])*weights[attr])
	if(weightInp+bias>=0):
		return 1
	else:
		return 0

def correctWeights(weights,bias,data,opDiff):
	for attr in range(totalAttr):
		weights[attr]+=(learningRate*opDiff*float(data[attr]))
	bias+=(learningRate*opDiff)
	return weights,bias

def main():
	filename=sys.argv[1]
	fields, rows=parseCSV(filename)
	shuffle(rows)

	train_st=0
	weights=[1/totalFields for _ in range(totalAttr)]
	bias=0
	trainAndCrossValidate(rows,weights,bias)
	fold_val = [i for i in range(1,11)]
  
  #Plot of accuracy for each fold 
	plt.plot(fold_val,fold_Accuracy)
	plt.xlabel("fold")
	plt.ylabel("Accuracy")
	plt.show()
	print(fold_Accuracy)

main()
