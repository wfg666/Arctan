/*************************************************************/
/*                     数值分析第二次大作业                     */
/*  马浩程   自34   2013011504  mhc13@mails.tsinghua.edu.cn   */
/*************************************************************/

#include "arctan.h"
#include <ctime>
using namespace std;

int FPNum::accuracy = 20;

void printHello();
void printHelp();

int main(int argc, char *args[])
{
    printHello();
    printHelp();


    while(true)
        try
        {
            //提示输入
            cout<<">>>";
            fflush(stdout);

            char s[200];
            cin.getline(s,1000);

            //输入q退出
            if(s[0]=='q')
                break;

            //输入a切换精度
            if(s[0]=='a' && s[1]==' ')
            {
                int accuracy;
                if (sscanf(s+2,"%d",&accuracy)<0)
                    throw "输入错误,要改变精度请输入a+空格+精度,如a 20";
                if (accuracy<6)
                    throw "小数位数必须大于5";
                FPNum::accuracy=(accuracy/4+((accuracy%4)?1:0))*4;
                cout<<"小数精度切换至"<<accuracy<<"位."<<endl<<endl;
                continue;
            }

            //三种方法计算arctan(x)
            FPNum nt,ns,nr,na(s);
            clock_t t1,t2;

            t1=clock();
            nt=arctan_taylor(na);
            t2=clock();
            cout<<"泰勒公式法:"<<nt<<"  时间(ms):"<<(t2-t1)*1000./CLOCKS_PER_SEC;

            t1=clock();
            ns=arctan_simpson(na);
            t2=clock();
            cout<<"\n复化辛普森:"<<nt<<"  时间(ms):"<<(t2-t1)*1000./CLOCKS_PER_SEC;

            t1=clock();
            nr=arctan_romberg(na);
            t2=clock();
            cout<<"\n龙贝格方法:"<<nt<<"  时间(ms):"<<(t2-t1)*1000./CLOCKS_PER_SEC<<endl<<endl;

        }
        catch (char const *s)
        {
            cout<<s<<endl<<endl<<endl;
            fflush(stdin);
            printHelp();
        }
    return 0;
}


void printHelp()
{
    cout<<"·输入自变量的值即可计算Arctan的值,可接受标准的十进制小数输入,如:"<<endl;
    cout<<"    0   123   12.45   0.123   123.   -.123   -123.45"<<endl;
    cout<<"·默认精度为保留20位小数,输入a和要保留的小数位数可改变精度,如:"<<endl;
    cout<<"    >>>a 30\n    小数精度切换至30位."<<endl;
    cout<<"·输入q退出.                  马浩程 自34 2013011504"<<endl;
}