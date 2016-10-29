//------------------------------------------------------------------------------
#include <string>
#include <stdio>
#include <stdlib>
#include <math>


#pragma hdrstop

#include "kostik_fround.h"

//------------------------------------------------------------------------------

#pragma package(smart_init)


//------------------------------------------------------------------------------
void left_cut(char * tmpstr)
{
	const int
    	point_pos = (int)(strchr(tmpstr,'.')-tmpstr);
    int
		endpos = strlen(tmpstr)-1;
   	if (point_pos==NULL)
    	return;
    while(tmpstr[endpos]=='0')
    {

		tmpstr[endpos]=0;
        if (endpos>0)
        	endpos--;
        else
        	return;
    }

}
//------------------------------------------------------------------------------
int isOneDigit(char * tmpstr)
{
	const int tmpStrLen = std::strlen(tmpstr);
	int cnt = 0;
	for ( int i=0; i<tmpStrLen; i++)
    {
		if ((tmpstr[i]!='0')&&(tmpstr[i]!='.'))
        {
			cnt++;
      	}
	}
    if (cnt==1)
    {
   		cnt = 0;
   	}
	return cnt;
}
//------------------------------------------------------------------------------
double KostikFRound(double input,int dig)
{
	enum {TMPSTRLEN = 50 };
	char tmpstr[TMPSTRLEN+1];
	int endpos, need_round;
	double znak=1;
	double tmp;


	if (input>0)
    {
		tmp=input;
   	}
   	else
   	{
		tmp=-input;
      	znak = -1;
   	}
	//Covert to string
	snprintf(tmpstr, TMPSTRLEN, "0%.8f", tmp);
    int point_pos = (int)(strchr(tmpstr,'.')-tmpstr);

	//   cout<<"\r\n point_pos+dig+2="<<(point_pos+dig+2);
   	tmpstr[point_pos+dig+2]=0;
   	//Clear left
	left_cut(tmpstr);
	//   cout<<"\r\n leftcut = "<<tmpstr;
	//Test one digit
	if (isOneDigit(tmpstr)==0)
    {
		//   	cout<<"\r\n OneDigit=0";
   		tmp = atof(tmpstr);
	   	tmp*=znak;
		return tmp;
   	}
	//Calc new params of string
   	endpos = strlen(tmpstr)-1;
	point_pos = (int)(strchr(tmpstr,'.')-tmpstr);

	if (endpos==(dig+point_pos))
    {
		//   	cout<<"\r\n endpos==(dig+point_pos)";
   		tmp = atof(tmpstr);
		tmp*=znak;
		return tmp;
   	}
	need_round=0;
	//   cout<<"point_pos="<<point_pos<<" endpos="<<endpos;
   	if (tmpstr[endpos]<'5')
    {
		//   	cout<<"\r\nsym<5";
    	if (point_pos<endpos)
        {
			//			cout<<"\r\npoint_pos<<endpos ";
			tmpstr[endpos]=0;
      	}else
        {
      		if (point_pos==endpos)
            {
				//		   		cout<<"\r\npoint_pos==endpos";
				tmpstr[endpos+1]='0';
				tmpstr[endpos+2]=0;
         	}
            else
            {
				tmpstr[endpos]='0';
         	}
      	}
   	}
    else
    {
		//     	cout<<"\r\nsym>=5";
      	if (point_pos<endpos)
        {
			tmpstr[endpos]=0;
      	}
        else
        {
      		if (point_pos==endpos)
            {
				//		   	cout<<"\r\npoint_pos==endpos";
				tmpstr[endpos+1]='0';
				tmpstr[endpos+2]=0;
         	}
            else
            {
				tmpstr[endpos]='0';
         	}
      	}
		do
        {
        	endpos--;
  	      	if (tmpstr[endpos]=='.')
          	{
            	endpos--;
          	}
          	//		  	cout<<"\r\nnext endpos="<<endpos;
		  	//		  	cout<<"\r\ncur val="<<tmpstr[endpos];
		  	tmpstr[endpos]++;
		  	//	  		cout<<"\r\nnext val="<<tmpstr[endpos];
		  	if (tmpstr[endpos]>'9')
          	{
            	//				cout<<"\r\n val>9 Need round.";
				tmpstr[endpos]='0';
				need_round=1;
          	}
            else
          	{
				//	cout<<"\r\n val<=9 Not need round.";
				need_round=0;
          	}
      	}
        while(need_round==1);
	}
	//   cout<<"\r\nRESULT "<<tmpstr<<".";
	tmp = atof(tmpstr);
   	tmp*=znak;
   	return tmp;
}
//------------------------------------------------------------------------------
double KostikGOSTRound(double input,int * point)
{
	double tmp;
	enum {TMPSTRLEN = 50 };
	char tmpstr[TMPSTRLEN+1];
	int point_pos;
	int fdigit_pos;
	int dig;

	snprintf(tmpstr,TMPSTRLEN,"%f",input);
	left_cut(tmpstr);
	//   cout<<"tmpstr="<<tmpstr;
   	fdigit_pos = strcspn(tmpstr,"123456789");
	//   cout<<"\r\nlength="<<strlen(tmpstr);
	//	cout<<"\r\nfdigit_pos="<<fdigit_pos;
	point_pos = (int)(strchr(tmpstr,'.')-tmpstr);

	//   cout<<"\r\n digits="<<(fdigit_pos-point_pos);
   	dig = fdigit_pos-point_pos;
   	if (dig<0)
    {
		dig=0;
   	}
	//   cout<<"\r\n dig="<<dig;

   	if (tmpstr[fdigit_pos]>='3')
    {
   		tmp = KostikFRound(input,dig);
      	*point =dig;
		//	   cout<<"\r\n OUTdig="<<dig;
      	return tmp;
   }
   else
   {
   		tmp = KostikFRound(input,dig+1);
		fdigit_pos = strcspn(tmpstr,"123456789");
		snprintf(tmpstr,TMPSTRLEN,"%f",tmp);

        if (tmpstr[fdigit_pos]<'3')
        {
	      	*point =dig+1;
			//		   	cout<<"\r\n OUTdig+1="<<(dig+1);
      	}
        else
        {
			//		   cout<<"\r\n OUTdig="<<dig;
	      	*point =dig;
      	}
      	return tmp;
   }
}
//------------------------------------------------------------------------------
void HromatNormValIndet(double& val, double& indet )
{
    int dig = 0;
    indet = KostikGOSTRound( indet, &dig );
	val = KostikFRound( val, dig );
}

void MakeKostikFRound( double &val, int dig )
{
    val = KostikFRound( val, dig );
}


