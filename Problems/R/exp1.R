f <- function(x) {
  return(x^2 - 2*x)
}
curve(f, from = -5, to = 5, xlab = "x", ylab = "f(x)", main = "Plot of f(x) = x^2 - 2x")

min_x <- 1
min_y <- f(min_x)
points(min_x, min_y, col = "red", pch = 19)

z<-read.csv("disastersim01-1.csv")
plot(z$landX,z$landY, main = "land position", col="red")

x<- c(1,2,3)
y<-c(2,1,-3)
z<-x%*%y

m1 <- matrix(c(1, 4, 2, 5), nrow = 2, ncol = 2)
m2 <- matrix(c(1, 0, 0, 2), nrow = 2, ncol = 2)

m1t<-t(m1)
m2t<-t(m2)

m1m2s<-m1+m2

m1m2p <- m1 %*% m2

m2m1p<- m2%*%m1

m1m2p==m2m1p

sofx<-sum(x)
