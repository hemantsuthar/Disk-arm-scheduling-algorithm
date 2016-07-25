#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
void main()
{
	int a[2][40]={{0}},R,b[10],i=0,j,count=0;
	clrscr();
	for(i=0;i<40;i++)
	{
		a[0][i]=i+1;
	}
	cout<<"\nENTER WHERE IS READ HEAD:";
	cin>>R;
	cout<<"\nENTER NUMBER OF REQUESTS:";
	cin>>j;
	cout<<"\nNOW ENTER YOUR REUESTS:\n\n";
	for(i=0;i<j;i++)
	{
		cout<<"("<<i+1<<").";
		cin>>b[i];
	}
	clrscr();
/*	for(i=0;i<j;i++)
	{
		for(int k=i;k<j;k++)
		{
			if(b[i]>b[k])
			{
				int z=0;
				z=b[i];
				b[i]=b[k];
				b[k]=z;
			}
		}
	}     */
//	for(i=0;i<j;i++)
//	cout<<"\n"<<b[i];
	int temp=R,ans=0;
	cout<<"\n--------------------------------------------------------------------------------";
	cout<<"\n\t\t\t\tFCFS ALGORITHM";
	cout<<"\n--------------------------------------------------------------------------------";
	for(i=0;i<j;i++)
	{
		for(int k=0;k<40;k++)
		{
			if(b[i]==a[0][k])
			{
				ans=ans+fabs(b[i]-temp);
				a[1][k]=++count;
				temp=b[i];
			}
		}
	}
/*	for(i=0;i<2;i++)
	{
		for(int k=0;k<40;k++)
		{
			cout<<a[i][k]<<" ";
		}
		cout<<"\n";
	}      */
	cout<<"\nTOTAL NO. OF CYLINDERS:"<<ans;
	cout<<"\n--------------------------------------------------------------------------------";
	getch();
	cout<<"\n\t\t\t\tSSF ALGORITHM";
	cout<<"\n--------------------------------------------------------------------------------\n";
	temp=R;
	int h[10][10]={{0}},h1[20]={0};
	for(i=0;i<j+1;i++)
	{
		if(i==0)
		{
			h1[i]=R;
		}
		else
		{
			h1[i]=b[i-1];
		}
	}
	for(i=0;i<j+1;i++)
	{
		for(int k=0;k<j+1;k++)
		{
				h[i][k]=fabs(h1[k]-h1[i]);
		}
	}
/*	for(i=0;i<j+1;i++)
	{
		for(int k=0;k<j+1;k++)
		{
			cout<<h[i][k]<<" ";
		}
		cout<<"\n";
	} */
	int an[10],sp=0,c=0;
	for(i=0;i<j;i++)
	{
		int jadu=58;
		if(i!=0)
		sp=an[i-1];
		for(int k=1;k<j+1;k++)
		{
			if(k!=sp)
			{
				if(jadu>=h[sp][k])
				{
					for(int lc=0;lc<c;lc++)
					{
						if(an[lc]==k)
						goto xyz;
					}
					jadu=h[sp][k];
					an[c]=k;
				}
			}
			xyz:
		}
		c++;
	}
	int sum=0;
	for(i=1;i<j;i++)
	{
		sum=sum+fabs(h1[an[i]]-h1[an[i-1]]);
	}
	sum=sum+fabs(h1[an[0]]-h1[0]);
	cout<<"TOTAL NO. OF CYLINDERS:";
	cout<<sum;
	cout<<"\n--------------------------------------------------------------------------------";
	getch();
	cout<<"\n\t\t\t\tELEVATOR ALGORITHM";
	cout<<"\n--------------------------------------------------------------------------------";
	for(i=0;i<j;i++)
	{
		for(int k=i;k<j;k++)
		{
			if(b[i]>b[k])
			{
				int z=0;
				z=b[i];
				b[i]=b[k];
				b[k]=z;
			}
		}
	}
	int cnt=0,cnt1=0,si[10]={0};
	int sum1=0;
	for(i=0;i<j;i++)
	{
		if(b[i]>R)
		{
			si[cnt1]=b[i];
			b[i]=0;
			cnt1++;
		}
		else
		cnt++;
	}
	if(fabs(b[cnt-1]-R)<fabs(si[0]-R))
	{
		sum1=sum1+fabs(R-b[cnt-1]);
		for(i=cnt-2;i>=0;i--)
		{
			sum1=sum1+fabs(b[i+1]-b[i]);
		}
		sum1=sum1+fabs(b[0]-si[0]);
		for(i=1;i<=cnt1-1;i++)
		{
			sum1=sum1+fabs(si[i-1]-si[i]);
		}
	}
	else
	{
		sum1=sum1+fabs(R-si[0]);
		for(i=1;i<=cnt1-1;i++)
		{
			sum1=sum1+fabs(si[i-1]-si[i]);
		}
		sum1=sum1+fabs(b[cnt-1]-si[cnt1-1]);
		for(i=cnt-2;i>=0;i--)
		{
			sum1=sum1+fabs(b[i+1]-b[i]);
		}
	}
	cout<<"\nTOTAL NO. OF CYLINDERS="<<sum1;
	cout<<"\n--------------------------------------------------------------------------------";
	delay(500);
	for(i=1;i<=7;i++)
	{
		clrscr();
		if(kbhit())
		break;
		gotoxy(30,11);
		cout<<"PRESS ENTER FOR RESULTS";
		delay(200);
		cout<<".";
		delay(200);
		cout<<".";
		delay(200);
		cout<<".";
		delay(200);
	}
	gotoxy(1,11);
	getch();
	cout<<"\n================================================================================";
	if(ans<sum)
	{
		if(ans<sum1)
		cout<<"\t\tEFFICIENT ALGORITHM::::::::FCFS";
		else
		cout<<"\t\tEFFICIENT ALGORITHM::::::::ELEVATOR";
	}
	else
	{
		if(sum<sum1)
		cout<<"\t\tEFFICIENT ALGORITHM::::::::SSF";
		else
		cout<<"\t\tEFFICIENT ALGORITHM::::::::ELEVATOR";
	}
	cout<<"\n================================================================================";
	getch();
}