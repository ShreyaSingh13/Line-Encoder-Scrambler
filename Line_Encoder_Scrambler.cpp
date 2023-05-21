#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
string lcs(string &x,string &y){
 int m=x.size();
 int n=y.size();
 int dp[m+1][n+1];
 for(int i=0;i<=m;i++) {
 for(int j=0;j<=n;j++) {
 if(i==0 || j==0)
 dp[i][j]=0;
 else if(x[i-1]==y[j-1])
 dp[i][j]=dp[i-1][j-1]+1;
 else
 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
 }
 }
 int index=dp[m][n];
 string temp(index+1,'\0');
 int i=m,j=n;
 while(i>0 && j>0) {
 if(x[i-1]==y[j-1]) {
 temp[index-1]=x[i-1];
 i--;
 j--;
 index--;
 }
 else if(dp[i-1][j]>dp[i][j-1])
 i--;
 else
 j--;
 }
 return temp;
}
string longPal(string &str){
 string rev=str;
 reverse(rev.begin(),rev.end());
 return lcs(str,rev);
}
void NRZL(string p){
 int n=p.size();
 settextstyle(0,0,0);
 int x=20;
 for(int i=0;i<n;i++){
 if(p[i]=='0'){
 line(x,100,x+40,100);
 outtextxy(x+18,25,"0");
 }
 else if(p[i]=='1') {
 rectangle(x,50,x+40,100);
 outtextxy(x+16,25,"1");
 setcolor(0);
 line(x,100,x+40,100);
 if(p[i-1]=='1' && i>0)
 {setcolor(0);line(x,50,x,100);}
 setcolor(15);
 }
 x=x+40;
 }
 settextstyle(0,1,2);
 outtextxy(0,150,"Amp----->");
}
void NRZI(string p){
 int n=p.size();
 settextstyle(0,0,0);
 int x=20,flag=0;
 if(p[0]=='0') {
 line(x,100,x+40,100);
 outtextxy(x+18,25,"0");
 flag=0;
 }
 else {
 rectangle(x,50,x+40,100);
 outtextxy(x+18,25,"1");
 setcolor(0);
 line(x,100,x+40,100);
 flag=1;
 setcolor(15);
 }
 x=x+40;
 for(int i=1;i<n;i++) {
 if(p[i]=='0')
 {outtextxy(x+18,25,"0");
 if(flag==0){
 line(x,100,x+40,100);
 flag=0;
 }
 else if(flag==1) {
 rectangle(x,50,x+40,100);
 setcolor(0);
 line(x,100,x+40,100);
 setcolor(15);
 flag=1;
 }
 x=x+40;
 }
 else if(p[i]=='1'){
 outtextxy(x+18,25,"1");
 if(flag==1){
 line(x,100,x+40,100);
 flag=0;
 }
 else if(flag==0) {
 rectangle(x,50,x+40,100);
 setcolor(0);
 line(x,100,x+40,100);
 setcolor(15);
 flag=1;
 }
 x=x+40;
 }}
 settextstyle(0,1,2);
 outtextxy(0,150,"Amp----->");
}
string generateRand(int n){
vector<int>vec;
 string ans;
 srand((unsigned int) time(0));
 for(int i=1;i<=n;i++) {
 vec.push_back(i);
 vec[i]=rand()%2;
 ans.push_back(vec[i]+'0');
 }
 return ans;
}
void MANCHESTER(string p){
 int n=p.size();
 int x=20;
 for(int i=0;i<n;i++) {
 if(p[i]=='0'){
 rectangle(x,100,x+20,200);
 outtextxy(x+18,25,"0");
 setcolor(0);
 line(x,100,x+20,100);
 line(x,100,x,200);
 setcolor(15);
 line(x+20,100,x+40,100);
 }
 else if(p[i]=='1')
 {
 rectangle(x,100,x+20,200);
 outtextxy(x+18,25,"1");
 setcolor(0);
 line(x,200,x+20,200);
 line(x,100,x,200);
 setcolor(15);
 line(x+20,200,x+40,200);
 }
 x=x+40;
 }
 settextstyle(0,1,2);
 outtextxy(0,150,"Amp----->");
}
void DIFMAN(string p){
 int n=p.size();
 int x=20,flag=0;
 if(p[0]=='0') {
 rectangle(x,100,x+20,200);
 outtextxy(x+18,25,"0");
 setcolor(0);
 line(x,100,x+20,100);
 line(x,100,x,200);
 setcolor(15);
 line(x+20,100,x+40,100);
 flag=0;
 }
 else if(p[0]=='1') {
 rectangle(x,100,x+20,200);
 outtextxy(x+18,25,"1");
 setcolor(0);
 line(x,200,x+20,200);
 line(x,100,x,200);
 setcolor(15);
 line(x+20,200,x+40,200);
 flag=1;
 }
 x=x+40;
 for(int i=1;i<n;i++){
 if(p[i]=='0'){
 if(flag==0) {
 rectangle(x,100,x+20,200);
 outtextxy(x+18,25,"0");
 setcolor(0);
 line(x,100,x+20,100);
 line(x,100,x,200);
 setcolor(15);
 line(x+20,100,x+40,100);
 }
 else if(flag==1) {
 rectangle(x,100,x+20,200);
 outtextxy(x+18,25,"1");
 setcolor(0);
 line(x,200,x+20,200);
 line(x,100,x,200);
 setcolor(15);
 line(x+20,200,x+40,200);
 }
 x=x+40;
 }
 else if(p[i]=='1')
 {
 if(flag==1) {
 rectangle(x,100,x+20,200);
 outtextxy(x+18,25,"1");
 setcolor(0);
 line(x,100,x+20,100);
 line(x,100,x,200);
 setcolor(15);
 line(x+20,100,x+40,100);
 flag=0;
 }
 else if(flag==0) {
 rectangle(x,100,x+20,200);
 outtextxy(x+18,25,"1");
 setcolor(0);
 line(x,200,x+20,200);
 line(x,100,x,200);
 setcolor(15);
 line(x+20,200,x+40,200);
 flag=1;
 }
 x=x+40;
 }}
 settextstyle(0,1,2);
 outtextxy(0,200,"Amp----->");
}
void AMI(string p){
 int n=p.size();
 int x=20,flag=0;
 for(int i=0;i<n;i++) {
 if(p[i]=='0')
 {line(x,100,x+40,100);
 outtextxy(x+18,30,"0");
 }
 else if(p[i]=='1'){
 if(flag==0) {
 rectangle(x,50,x+40,100);
 outtextxy(x+18,30,"1");
 setcolor(0);
 line(x,100,x+40,100);
 setcolor(15);
 flag=1;
 }
 else{
 rectangle(x,100,x+40,150);
 outtextxy(x+18,30,"1");
 setcolor(0);
 line(x,100,x+40,100);
 setcolor(15);
 flag=0;
 }
 }
 x=x+40;
 }
 settextstyle(1,1,1);
 outtextxy(0,150,"Amp----->");
}
void B8ZS(string p,int &flag1,int &x){
 int flag;
 int n=p.size();
 for(int i=0;i<n;i++) {
 if(i==3||i==7){
 if(flag1==0)
 flag=1;
 else
 flag=0;
 }
 if(i==4||i==6)
 { flag=flag1;
 }
 if(p[i]=='0'&& i!=4 && i!=3 && i!=6 && i!=7)
 {line(x,100,x+40,100);
 outtextxy(x+18,30,"0");
 }
 else
 {
 if(flag==0) {
 rectangle(x,50,x+40,100);
 outtextxy(x+18,30,"0");
 setcolor(0);
 line(x,100,x+40,100);
 setcolor(15);
 flag=1;
 }
 else
 {rectangle(x,100,x+40,150);
 outtextxy(x+18,30,"0");
 setcolor(0);
 line(x,100,x+40,100);
 setcolor(15);
 flag=0;
 }
 }
 x=x+40;
 }
 flag1=flag;
 settextstyle(1,1,1);
 outtextxy(0,150,"Amp----->");
 }
void AMIB8ZS(string p){
 int n=p.size();
 if(n==8){
 int x=20,flag=0;
 if(p=="00000000") {
 B8ZS(p,flag,x);
 }
 else
 AMI(p);
 }
 else if(n<8)
 AMI(p);
 else {
 int x=20,flag=0;
 for(int i=0;i<n;i++) {
 if(p[i]=='0'){
 string substring=p.substr(i,8);
 if(substring=="00000000")
 {B8ZS(substring,flag,x);
 i=i+7;
 continue;}
 }
 settextstyle(1,0,1);
 if(p[i]=='0')
 {line(x,100,x+40,100);
 outtextxy(x+18,30,"0");
 }
 else if(p[i]=='1'){
 if(flag==0){
 rectangle(x,50,x+40,100);
 outtextxy(x+18,30,"1");
 setcolor(0);
 line(x,100,x+40,100);
 setcolor(15);
 flag=1;
 }
 else{
 rectangle(x,100,x+40,150);
 outtextxy(x+18,30,"1");
 setcolor(0);
 line(x,100,x+40,100);
 setcolor(15);
 flag=0;
 }
 }
 x=x+40;
 }
 settextstyle(1,1,1);
 outtextxy(0,150,"Amp----->");
 }
}
void HDB3(string p,int &flag1,int &x,int sum){
 int flag,n;
 n=p.size();
 for(int i=0;i<n;i++){
if(sum%2==0)
 {if(i==0||i==3)
 {
 flag=flag1;
 }}
 else
 {if(i==3)
 {if(flag1==0)
 flag=1;
 else
 flag=0;
 }}
 if(p[i]=='0'&& i!=3 && i!=0 ||(i==0 && (sum%2!=0 )))
 {line(x,100,x+40,100);
 outtextxy(x+18,30,"0");
 }
 else
 {
 if(flag==0) {
 rectangle(x,50,x+40,100);
 outtextxy(x+18,30,"0");
 setcolor(0);
 line(x,100,x+40,100);
 setcolor(15);
 flag=1;
 }
 else
 {rectangle(x,100,x+40,150);
 outtextxy(x+18,30,"0");
 setcolor(0);
 line(x,100,x+40,100);
 setcolor(15);
 flag=0;
 }
 }
 x=x+40;
 }
 flag1=flag;
 settextstyle(1,1,1);
 outtextxy(0,150,"Amp----->");
}
void AMIHDB3(string p){
 int n=p.size();
 int x=20,flag=0,sum=0;
 for(int i=0;i<n;i++) {
 if(p[i]=='0') {
 string sub=p.substr(i,4);
 if(sub=="0000")
 {HDB3(sub,flag,x,sum);
 i=i+3;
 continue;
 }
 }
 settextstyle(1,0,1);
 if(p[i]=='0')
 {line(x,100,x+40,100);
 outtextxy(x+18,30,"0");
 }
 else if(p[i]=='1'){
 sum++;
 if(flag==0) {
 rectangle(x,50,x+40,100);
 outtextxy(x+18,30,"1");
 setcolor(0);
 line(x,100,x+40,100);
 setcolor(15);
 flag=1;
 }
 else
 {rectangle(x,100,x+40,150);
 outtextxy(x+18,30,"1");
 setcolor(0);
 line(x,100,x+40,100);
 setcolor(15);
 flag=0;
 }
 }
 x=x+40;
 }
 settextstyle(1,1,1);
 outtextxy(0,150,"Amp----->");
}
int main(){
 int gd=DETECT,gm,choice,scramb;
 char ch;
 initgraph(&gd,&gm,(char*)"");
 setcolor(15);
 setfillstyle(2,5);
 settextstyle(1,0,1);
 string p,p1;
 p=generateRand(15);
 p1=longPal(p);
 cout<<p<<" "<<p1<<"\n";
 cout <<"------------Project By - Mousumi Biswas, Shagun Bhatt & Shreya------------\n\n\n";
// cout<<"Choose encoding scheme\n(1) For NRZ-L\n(2) For NRZ-I\n(3) For MANCHESTER\n(4) For DIFFERENTIAL MANCHESTER\n(5) For AMI\n";
cout<<"Choose encoding scheme------ 1. for NRZ-L  2.for NRZ-I  3.for MANCHESTER  4. for DIFFERENTIAL MANCHESTER  5.for AMI"<<endl;
 cin >> ws;
 cin>>choice;
 if(choice==1)
NRZL(p1);
else if(choice==2)
NRZI(p1);
else if(choice==3)
MANCHESTER(p1);
else if(choice==4)
DIFMAN(p1);
else if(choice==5){
cout<<"Require Scrambling (Y/N)?\n";
cin>>ch;
if(ch=='Y'){
cout<<"Type of scrambling:\n(1) B8ZS\n(2) HDB3\n";
cin>>scramb;
if(scramb==1)
AMIB8ZS(p1);
else
AMIHDB3(p1);
}}
else
AMI(p1);
 getch();
 closegraph();
}
