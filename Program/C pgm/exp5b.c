#include<stdio.h> 
#include <winsock2.h>
#include<sys/types.h> 
#include<netinet/in.h> 
#include<sys/socket.h> 
#include<string.h> 
void main() 
{ 
intsd,len,nsd,clilen; 
charsendmsg[30],recvmsg[20]; 
structsockaddr_incliaddr,servaddr; 
sd=socket(AF_INET,SOCK_STREAM,0); 
servaddr.sin_family=AF_INET; 
servaddr.sin_addr.s_addr=htonl(INADDR_ANY); 
servaddr.sin_port=htons(33345); 
bind(sd,(structsockaddr*)&servaddr,sizeof(servaddr)); 
listen(sd,5); 
clilen=sizeof(cliaddr);

nsd=accept(sd,(structsockaddr*)&cliaddr,&clilen); 
printf("\messages:"); 
do 
{ 
recv(nsd,recvmsg,20,0); 
printf("%s\n",recvmsg); 
fgets(sendmsg,20,stdin); 
len=strlen(sendmsg); 
sendmsg[len-1]='\0'; 
send(nsd,sendmsg,20,0); 
wait(20); 
} 
while(strcmp(sendmsg,”bye”)!=0); 
}
