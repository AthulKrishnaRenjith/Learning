#include<stdio.h>
#include <winsock2.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
void main()
{
int csd,len;
char sendmsg[30],recvmsg[20];
struct sockaddr_in cliaddr,servaddr;
csd=socket(AF_INET,SOCK_STREAM,0);
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(33345);
connect(csd,(structsockaddr*)&servaddr,sizeof(servaddr));
printf("\n messages:\n");
do
{
fgets(sendmsg,20,stdin);
len=strlen(sendmsg);
sendmsg[len-1]='\0';
send(csd,sendmsg,20,0);
wait(20);
recv(csd,recvmsg,20,0);
printf("%s\n",recvmsg);
}
while(strcmp(recvmsg,”bye”)!=0);
}
