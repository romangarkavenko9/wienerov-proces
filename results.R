library(ggplot2)

data<-read.table("celok.txt",sep=',',header=TRUE)
ggplot(data, aes(x=x, y=y, group=typ, colour=farba)) + geom_line()

cas2<-subset(data, data$x==0.001)
cas3<-subset(data, data$x==0.002)
ggplot(cas3, aes(x=cas2$y, y=y, group=typ, colour=farba)) + geom_point()