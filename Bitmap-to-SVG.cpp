#include<bits/stdc++.h>
#include<graphics.h>
char a[17]="0123456789abcdef";
int main(int argc,char* argv[]){
	char* path=argv[1];
	PIMAGE img=newimage();
	getimage(img,path);
	int w=getwidth(img);
	int h=getheight(img);
	freopen("output.svg","w",stdout);
	printf("<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"%d\" height=\"%d\">",w,h);
	for(int i=0;i<w;i++){
		for(int j=0;j<h;j++){
			color_t t=getpixel(i,j,img);
			int r=(t>>16)&255;
			int g=(t>>8)&255;
			int b=t&255;
			printf("<path d=\"M%d,%dl1,0l0,1l-1,0\" fill=\"#",i,j);
			printf("%c%c%c%c%c%c\"/>",a[r/16],a[r%16],a[g/16],a[g%16],a[b/16],a[b%16]);
		}
	}
	printf("</svg>");
	return 0;
}
