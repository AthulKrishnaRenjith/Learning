#task 1
confusionAnalysis = function(trueOutputs, predOutputs){
  tp = sum(trueOutputs==1 & predOutputs==1)
  tn = sum(trueOutputs==0 & predOutputs==0)
  fp = sum(trueOutputs==0 & predOutputs==1)
  fn = sum(trueOutputs==0 & predOutputs==1)
  
  return(list(tp=tp, tn=tn,fp=fp,fn=fn)) 
}

#task 2
accuracy = function(trueOutputs, predictedOutputs){
  confusionMatrix = confusionAnalysis(trueOutputs, predictedOutputs)
  
  tp = confusionMatrix$tp
  tn = confusionMatrix$tn
  fp = confusionMatrix$fp
  fn = confusionMatrix$fn
  
  accuracy_value = (tp+tn)/(tp+tn+fp+fn)
  
  return(accuracy_value)
}

#task 3
yTrue = c(T, F, F, T, F, T, F, T, T, T)
yPredicted = c(T, F, T, T, T, T, F, T, T, F)
confusionMatrix = confusionAnalysis(yTrue, yPredicted)
print(confusionMatrix)

accuracy_value = accuracy(yTrue,yPredicted)
print(accuracy_value)

#task4
library(class)

x1=c(0,2,4,3)
x2=c(0,2,0,3)

y = c(FALSE, TRUE,FALSE,TRUE)

p1 = c(0,1)
p2 = c(1,0)

x = cbind(x1,x2)

new_points = cbind(p1,p2)

prediction_k1 = knn(train=x,test=new_points,cl=y,k=1)

prediction_k3 = knn(train=x,test=new_points,cl=y,k=3)

print(prediction_k1)
print(prediction_k3)

#task 5
c = read.csv("disastersim01-1.csv")
b = cbind(c$landX,c$landY,c$parachuteSize,c$weight)
new_points=
pred_k1 = knn(train=b,test=new_points,cl=c$state,k=50)

print(pred_k1)
