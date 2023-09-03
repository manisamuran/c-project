#include<stdio.h>
#include<dos.h>
#include<dir.h>
#include<fcntl.h>
#include<conio.h>
void main(int argc,char *argv[]){
	char buf[512];
	int source,target,byt,done;
	struct ffblk ffblk;
	clrscr();
	textcolor(2);
	done=findfirst("*.*",&ffblk,0);
	while(!done)
	{
		cprintf("%s",ffblk.ff_name);
		source=open(ffblk.ff_name,O_RDONLY|O_BINARY);
		target=open(ffblk.ff_name,O_CREAT|O_BINARY|O_WRONLY);
		while(1)
		{
			byt=read(source,buf,512);
			if(byt>0)
			  write(target,buf,byt);
			else break;
		}
		close(source);
		close(target);
		done=findnext(&ffblk);
	}



	getch();
	return 0;
}
