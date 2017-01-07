#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>

using namespace std;
char UnitateM[7][3], UnitateA[7][5], UnitateV[7][5], TEMP[3][3], M[4][3], T[9][8], P[8][5], V[9][9], D[9][7], E[7][5], COMB[8][8];
float x;

ifstream finL("lungimi.in");
ifstream finA("arii.in");
ifstream finV("volume.in");
ifstream finTimp("timp.in");
ifstream finTemp("temperatura.in");
ifstream finMasa("mase.in");
ifstream finP("presiuni.in");
ifstream finVit("viteza.in");
ifstream finDens("densitate.in");
ifstream finE("energie.in");
ifstream finComb("combustibil.in");

void citirel()
{
    for (int i=0; i<=6; i++)
        finL>>UnitateM[i];
}
void lungime(float x)
{
    char y[3], mx[3];
    float rez;
    int poz_I, poz_F;
    cout<<"Introduceti lungimea initiala: ";
    cin>>x;
    cout<<"Introduceti unitatea de masura initiala (km/hm/dam/m/dm/cm/mm): ";
    cin>>mx;
    cin.get();
    cout<<"Introduceti unitatea de masura finala (km/hm/dam/m/dm/cm/mm): ";
    cin>>y;
    for (int j=0; j<=6; j++)
    {
        if (stricmp(y, UnitateM[j])==0)
            poz_F=j;
        if (stricmp(mx,UnitateM[j])==0)
            poz_I=j;
    }

    int d=poz_F-poz_I;
    rez=x*pow(10,d);
    cout<<rez<<" "<<UnitateM[poz_F]<<endl;;
}

void citirea()
{
    for (int j=0; j<=6; j++)
        finA>>UnitateA[j];
}

void arie (float x)
{
    char y[5], mx[5];
    int poz_I, poz_F;
    float rez;
    int d;
    cout<<"Introduceti aria initiala: ";
    cin>>x;
    cout<<"Introduceti unitatea de masura initiala (km^2/hm^2/dam^2/m^2/dm^2/cm^2/mm^2): ";
    cin>>mx;
    cout<<"Introduceti unitatea de masura finala (km^2/hm^2/dam^2/m^2/dm^2/cm^2/mm^2): ";
    cin>>y;
    for (int j=0; j<=6; j++)
    {
        if (stricmp(UnitateA[j],mx)==0)
            poz_I=j;
        if (stricmp(UnitateA[j],y)==0)
            poz_F=j;
    }
    d=poz_F-poz_I;
    rez=x*pow(100,d);
    cout<<rez<<" "<<UnitateA[poz_F]<<endl;

}

void citirev()
{
    for (int j=0; j<=9; j++)
        finV>>UnitateV[j];
}
void volum(float x)
{
    char y[5], mx[5];
    int poz_I, poz_F;
    int d;
    float rez;
    cout<<"Introduceti volumul initial: ";
    cin>>x;
    cout<<"Introduceti unitatea de masura initiala (km^3/hm^3/dam^3/m^3/dm^3/cm^3/mm^3): ";
    cin>>mx;
    cout<<"Introduceti unitatea de masura finala (km^3/hm^3/dam^3/m^3/dm^3/cm^3/mm^3): ";
    cin>>y;
    for (int j=0; j<=9; j++)
    {
        if (stricmp(UnitateV[j],mx)==0)
            poz_I=j;
        if (stricmp(UnitateV[j],y)==0)
            poz_F=j;
    }
    d=poz_F-poz_I;
    rez=x*pow(1000,d);
    cout<<rez<<" "<<UnitateV[poz_F]<<endl;
}

void cittemp()
{
    for (int j=0; j<=3; j++)
        finTemp>>TEMP[j];
}
void temperatura(float x)
{
    float tx, rez;
    int j, ti, tf;
    char y[3], yf[3];
    cout<<"Introduceti temperatura initiala: ";
    cin>>tx;
    cout<<"Introduceti unitatea de masura initiala (C/F/K/R): ";
    cin>>y;
    for (j=0; j<=3; j++)
        if (stricmp(y,TEMP[j])==0)
            ti=j;
    cout<<"Introduceti unitatea de masura finala (C/F/K/R): ";
    cin>>yf;
    for (j=0; j<=3; j++)
        if (stricmp(yf,TEMP[j])==0)
            tf=j;
    switch(ti)
    {
    case 0:
    {
        if (tf==1)
            rez=tx*1.8+32;
        else if (tf==2)
            rez=tx+273.15;
        else if (tf==3)
            rez=tx*1.8+32+459.67;
    }
    break;
    case 1:
    {
        if (tf==0)
            rez=(tx-32)/1.8;
        else if (tf==2)
            rez=(tx+459.67)/1.8;
        else if (tf==3)
            rez=tx+459.67;
    }
    break;
    case 2:
    {
        if (tf==0)
            rez=tx-273.15;
        else if (tf==1)
            rez=tx*1.8-459.67;
        else if(tf==3)
            rez=tx*1.8;
    }
    break;
    case 3:
    {
        if(tf==0)
            rez=(tx-32-459.67)/1.8;
        else if (tf==1)
            rez=tx-459.67;
        else if (tf==2)
            rez=tx/1.8;
    }
    break;
    }
    cout<<rez<<" "<<TEMP[tf]<<endl;
}

void citmasa()
{
    for (int j=0; j<=6; j++)
        finMasa>>M[j];
}
void masa(float x)
{
    char y[3], yf[3];
    int j, mi, mf;
    float rez;
    cout<<"Introduceti greutatea initiala: ";
    cin>>x;
    cout<<"Introduceti unitatea de masura initiala (mg/g/kg/t/lb/av/troy): ";
    cin>>y;
    for (j=0; j<=6; j++)
        if (stricmp(y,M[j])==0)
            mi=j;
    cout<<"Introduceti unitatea de masura finala (mg/g/kg/t/lb/av/troy): ";
    cin>>yf;
    for (j=0; j<=6; j++)
        if (stricmp(yf,M[j])==0)
            mf=j;
    switch(mi)
    {
    case 0:
    {
        if (mf==1)
            rez=x/1000;
        else if (mf==2)
            rez=x/1000000;
        else if (mf==3)
            rez=x/1000000000;
        else if (mf==4)
            rez=x*0.0000022046244201837775;
        else if (mf==5)
            rez=x*0.00003527399072294044;
        else if (mf==6)
            rez=x*0.00003215072258749015;
    }
    break;
    case 1:
    {
        if (mf==0)
            rez=x*1000;
        else if (mf==2)
            rez=x/1000;
        else if (mf==3)
            rez=x/1000000;
        else if (mf==4)
            rez=x*0.0022046244201837776;
        else if (mf==5)
            rez=x*0.03527399072294044;
        else if (mf==6)
            rez=x*0.03215072258749015;
    }
    break;
    case 2:
    {
        if (mf==0)
            rez=x*1000000;
        else if (mf==1)
            rez=x*1000;
        else if (mf==3)
            rez=x/1000;
        else if (mf==4)
            rez=x*2.2046244201837775;
        else if (mf==5)
            rez=x*35.27399072294044;
        else if (mf==6)
            rez=x*32.15072258749016;
    }
    break;
    case 3:
    {
        if (mf==0)
            rez=x*1000000000;
        else if (mf==1)
            rez=x*1000000;
        else if (mf==2)
            rez=x*1000;
        else if (mf==4)
            rez=x*2204.6244201837776;
        else if (mf==5)
            rez=x*35273.99072294044;
        else if (mf==6)
            rez=x*32150.722587490156;
    }
    break;
    case 4:
    {
        if (mf==0)
            rez=x*453592;
        if (mf==1)
            rez=x*453.592;
        if (mf==2)
            rez=x*0.453592;
        if (mf==3)
            rez=x*0.000453592;
        if (mf==5)
            rez=x*16;
        if (mf==6)
            rez=x*14.583310559904834;
    }
    break;
    case 5:
    {
        if (mf==0)
            rez=x*28349.5;
        if (mf==1)
            rez=x*28.3495;
        if (mf==2)
            rez=x*0.0283495;
        if (mf==3)
            rez=x*0.0000283495;
        if (mf==4)
            rez=x*0.0625;
        if (mf==6)
            rez=x*0.9114569099940522;
    }
    break;
    case 6:
    {
        if (mf==0)
            rez=x*31103.5;
        if (mf==1)
            rez=x*31.103499999999997;
        if (mf==2)
            rez=x*0.0311035;
        if (mf==3)
            rez=x*0.0000311035;
        if (mf==4)
            rez=x*0.06857153565318612;
        if (mf==5)
            rez=x*1.097144570450978;
    }
    }
    cout<<rez<<" "<<M[mf]<<endl;
}
void cittimp()
{
    for (int j=0; j<=9; j++)
        finTimp>>T[j];
}
void timp (float x)
{
    char y[8], yf[8];
    float rez;
    int ti, tf, j;
    cout<<"Introduceti timpul initial: ";
    cin>>x;
    cout<<"Introduceti unitatea de masura initiala (sec/min/ore/zile/sapt/luni/ani/deceniu/secol/mileniu): ";

    cin>>y;
    for (j=0; j<=9; j++)
        if (stricmp(y,T[j])==0)
            ti=j;
    cout<<"Introduceti unitatea de masura finala (sec/min/ore/zile/sapt/luni/ani/deceniu/secol/mileniu): ";
    cin>>yf;
    for (j=0; j<=9; j++)
        if (stricmp(yf,T[j])==0)
            tf=j;
    switch(ti)
    {
    case 0:
    {
        switch(tf)
        {
        case 1:
            rez=x/60;
            break;
        case 2:
            rez=x/3600;
            break;
        case 3:
            rez=x/3600/24;
            break;
        case 4:
            rez=x/3600/24/7;
            break;
        case 5:
            rez=x/3600/24/7/30;
            break;
        case 6:
            rez=x/3600/24/7/30/365;
            break;
        case 7:
            rez=x*3.1709791983764586*2.71;
            break;
        case 8:
            rez=x*3.17323314378554*2.71;
            break;
        case 9:
            rez=x*3.1732331437855403*2.71;
            break;
        }
        break;
    }

    case 1:
    {
        switch(tf)
        {
        case 0:
            rez=x*60;
            break;
        case 2:
            rez=x/60;
            break;
        case 3:
            rez=x/60/24;
            break;
        case 4:
            rez=x/60/24/7;
            break;
        case 5:
            rez=x/60/24/7/30;
            break;
        case 6:
            rez=x/60/24/7/30/365;
            break;
        case 7:
            rez=x*1.9025875190258752*2.71;
            break;
        case 8:
            rez=x*1.9039398862713242*2.71;
            break;
        case 9:
            rez=x*1.903939886271324*2.71;
            break;
        }
        break;
    }

    case 2:
    {
        switch(tf)
        {
        case 0:
            rez=x*3600;
            break;
        case 1:
            rez=x*60;
            break;
        case 3:
            rez=x/24;
            break;
        case 4:
            rez=x/24/7;
            break;
        case 5:
            rez=x/24/7/30;
            break;
        case 6:
            rez=x/24/7/30/365;
            break;
        case 7:
            rez=x*0.000011415525114155251;
            break;
        case 8:
            rez=x*1.1423639317627944*2.71;
            break;
        case 9:
            rez=x*1.1423639317627945*2.71;
            break;
        }
        break;
    }

    case 3:
    {
        switch(tf)
        {
        case 0:
            rez=x*24*3600;
            break;
        case 1:
            rez=x*24*60;
            break;
        case 2:
            rez=x*24;
            break;
        case 4:
            rez=x/7;
            break;
        case 5:
            rez=x/7/30;
            break;
        case 6:
            rez=x/7/30/365;
            break;
        case 7:
            rez=x*0.000273972602739726;
            break;
        case 8:
            rez=x*0.000002741673436230707;
            break;
        case 9:
            rez=x*2.741673436230707*2.71;
            break;
        }
        break;
    }

    case 4:
    {
        switch(tf)
        {
        case 0:
            rez=x*7*24*3600;
            break;
        case 1:
            rez=x*7*24*60;
            break;
        case 2:
            rez=x*7*24;
            break;
        case 3:
            rez=x*7;
            break;
        case 5:
            rez=x/30;
            break;
        case 6:
            rez=x/30/365;
            break;
        case 7:
            rez=x*0.0019178082191780822;
            break;
        case 8:
            rez=x*0.000019191714053614946;
            break;
        case 9:
            rez=x*0.0000019191714053614947;
            break;
        }
        break;
    }

    case 5:
    {
        switch(tf)
        {
        case 0:
            rez=x*30*24*3600;
            break;
        case 1:
            rez=x*30*24*60;
            break;
        case 2:
            rez=x*30*24;
            break;
        case 3:
            rez=x*30;
            break;
        case 4:
            rez=x/7;
            break;
        case 6:
            rez=x/365;
            break;
        case 7:
            rez=x*0.008333333333333333;
            break;
        case 8:
            rez=x*0.000083392567018684;
            break;
        case 9:
            rez=x*0.0000083392567018684;
            break;
        }
        break;
    }

    case 6:
    {
        switch(tf)
        {
        case 0:
            rez=x*365*24*3600;
            break;
        case 1:
            rez=x*365*24*60;
            break;
        case 2:
            rez=x*365*24;
            break;
        case 3:
            rez=x*365;
            break;
        case 4:
            rez=x*365/7;
            break;
        case 5:
            rez=x*365/12;
            break;
        case 7:
            rez=x*0.1;
            break;
        case 8:
            rez=x*0.001000710804224208;
            break;
        case 9:
            rez=x*0.0001000710804224208;
            break;
        }
        break;
    }
    case 7:
    {
        switch (tf)
        {
        case 0:
            rez=x*315360000;
            break;
        case 1:
            rez=x*5256000;
            break;
        case 2:
            rez=x*87600;
            break;
        case 3:
            rez=x*3650;
            break;
        case 4:
            rez=x*521.4285714285714;
            break;
        case 5:
            rez=x*120;
            break;
        case 6:
            rez=x*10;
            break;
        case 8:
            rez=x*0.01000710804224208;
            break;
        case 9:
            rez=x*0.001000710804224208;
            break;
        }
        break;
    }
    case 8:
    {
        switch (tf)
        {
        case 0:
            rez=x*31513600000;
            break;
        case 1:
            rez=x*525226666.6666667;
            break;
        case 2:
            rez=x*8753777.777777778;
            break;
        case 3:
            rez=x*364740.74074074073;
            break;
        case 4:
            rez=x*52105.82010582011;
            break;
        case 5:
            rez=x*11991.476407914764;
            break;
        case 6:
            rez=x*999.2897006595637;
            break;
        case 7:
            rez=x*99.92897006595636;
            break;
        case 9:
            rez=x*0.1;
            break;
        }
        break;
    }
    case 9:
    {
        switch (tf)
        {
        case 0:
            rez=x*315136000000;
            break;
        case 1:
            rez=x*5252266666.666667;
            break;
        case 2:
            rez=x*87537777.77777778;
            break;
        case 3:
            rez=x*3647407.407407407;
            break;
        case 4:
            rez=x*521058.2010582011;
            break;
        case 5:
            rez=x*119914.76407914764;
            break;
        case 6:
            rez=x*9992.897006595636;
            break;
        case 7:
            rez=x*999.2897006595637;
            break;
        case 8:
            rez=x*10;
            break;
        }
    }
    }
    cout<<rez<<" "<<T[tf]<<endl;
}
void citpres()
{
    for (int j=0; j<=8; j++)
        finP>>P[j];
}
void presiune (float x)
{
    char y[5], yf[5];
    int pi, pf, j;
    double rez;
    cout<<"Introduceti marimea presiunii: ";
    cin>>x;
    cout<<"Introduceti unitatea de masura initiala (pa/bar/atm/kpa/mba/mca/mmhg/mpa/psi): ";
    cin>>y;
    for (j=0; j<=8; j++)
        if (stricmp(P[j],y)==0)
            pi=j;
    cout<<"Introduceti unitatea de masura finala (pa/bar/atm/kpa/mba/mca/mmhg/mpa/psi): ";
    cin>>yf;
    for (j=0; j<=8; j++)
        if (stricmp(yf,P[j])==0)
            pf=j;
    switch(pi)
    {
    case 0:
    {
        switch(pf)
        {
        case 1:
            rez=x*pow(10,-5);
            break;
        case 2:
            rez=x*9.8692059*pow(10,-6);
            break;
        case 3:
            rez=x*pow(10,-3);
            break;
        case 4:
            rez=x*pow(10,-2);
            break;
        case 5:
            rez=x*1020408*pow(10,-3);
            break;
        case 6:
            rez=x*7500617*pow(10,-2);
            break;
        case 7:
            rez=x*pow(10,-6);
            break;
        case 8:
            rez=x*14503773773017476*pow(10,-3);
            break;
        }
        break;
    }

    case 1:
    {
        switch (pf)
        {
        case 0:
            rez=x*100000;
            break;
        case 2:
            rez=x*0.9671821878;
            break;
        case 3:
            rez=x*98;
            break;
        case 4:
            rez=x*1000;
            break;
        case 5:
            rez=x*10;
            break;
        case 6:
            rez=x*735.0604490503765;
            break;
        case 7:
            rez=x*0.098;
            break;
        case 8:
            rez=x*14.213698297557126;
            break;
        }
        break;
    }

    case 2:
    {
        switch(pf)
        {
        case 0:
            rez=x*101325.2738;
            break;
        case 1:
            rez=x*1.0339313653061224;
            break;
        case 3:
            rez=x*101.32527379999999;
            break;
        case 4:
            rez=x*1033.9313653061224;
            break;
        case 5:
            rez=x*10.339313653061224;
            break;
        case 6:
            rez=x*760.0020536691873;
            break;
        case 7:
            rez=x*0.10132527379999999;
            break;
        case 8:
            rez=x*14.695988486842547;
            break;
        }
        break;
    }

    case 3:
    {
        switch(pf)
        {
        case 0:
            rez=x*1000;
            break;
        case 1:
            rez=x*0.01020408163265306;
            break;
        case 2:
            rez=x*0.009869205998632101;
            break;
        case 4:
            rez=x*10.204081632653061;
            break;
        case 5:
            rez=x*0.10204081632653061;
            break;
        case 6:
            rez=x*7.5006168270446585;
            break;
        case 7:
            rez=x*0.001;
            break;
        case 8:
            rez=x*0.14503773773017475;
            break;
        }
        break;
    }

    case 4:
    {
        switch(pf)
        {
        case 0:
            rez=x*98;
            break;
        case 1:
            rez=x*0.001;
            break;
        case 2:
            rez=x*0.0009671821878659459;
            break;
        case 3:
            rez=x*0.098;
            break;
        case 5:
            rez=x*0.01;
            break;
        case 6:
            rez=x*0.7350604490503766;
            break;
        case 7:
            rez=x*0.000098;
            break;
        case 8:
            rez=x*0.014213698297557125;
            break;
        }
        break;
    }

    case 5:
    {
        switch(pf)
        {
        case 0:
            rez=x*9800;
            break;
        case 1:
            rez=x*0.1;
            break;
        case 2:
            rez=x*0.09671821878659459;
            break;
        case 3:
            rez=x*9.8;
            break;
        case 4:
            rez=x*100;
            break;
        case 6:
            rez=x*73.50604490503765;
            break;
        case 7:
            rez=x*0.0098;
            break;
        case 8:
            rez=x*1.4213698297557125;
            break;
        }
        break;
    }

    case 6:
    {
        switch(pf)
        {
        case 0:
            rez=x*133.322368421;
            break;
        case 1:
            rez=x*0.0013604323308265306;
            break;
        case 2:
            rez=x*0.0013157859181723722;
            break;
        case 3:
            rez=x*0.13332236842099998;
            break;
        case 4:
            rez=x*1.3604323308265305;
            break;
        case 5:
            rez=x*0.013604323308265305;
            break;
        case 7:
            rez=x*0.000133322368421;
            break;
        case 8:
            rez=x*0.01933677470461073;
            break;
        }
        break;
    }

    case 7:
    {
        switch(pf)
        {
        case 0:
            rez=x*1000000;
            break;
        case 1:
            rez=x*10.204081632653061;
            break;
        case 2:
            rez=x*9.8692059986321;
            break;
        case 3:
            rez=x*1000;
            break;
        case 4:
            rez=x*10204.081632653062;
            break;
        case 5:
            rez=x*102.04081632653062;
            break;
        case 6:
            rez=x*7500.616827044659;
            break;
        case 8:
            rez=x*145.03773773017474;
            break;
        }
        break;
    }

    case 8:
    {
        switch(pf)
        {
        case 0:
            rez=x*6894.75729317;
            break;
        case 1:
            rez=x*0.07035466625683673;
            break;
        case 2:
            rez=x*0.06804578003686579;
            break;
        case 3:
            rez=x*6.89475729317;
            break;
        case 4:
            rez=x*70.35466625683674;
            break;
        case 5:
            rez=x*0.7035466625683673;
            break;
        case 6:
            rez=x*51.714932571539784;
            break;
        case 7:
            rez=x*0.00689475729317;
            break;
        }
    }
    }
    cout<<rez<<" "<<P[pf]<<endl;
}
void citirevit()
{
    for (int j=0; j<=9; j++)
        finVit>>V[j];
}
void viteza(float x)
{
    char y[7], yf[7];
    int j, vi, vf;
    double rez;
    cout<<"Introduceti viteza initiala: ";
    cin>>x;
    cout<<"Introduceti unitatea de masura initiala (cm/s km/h km/min km/s m/h m/min m/s cm/min fph fps): ";
    cin>>y;
    for (j=0; j<=9; j++)
        if (stricmp(y,V[j])==0)
            vi=j;
    cout<<"Introduceti unitatea de masura finala (cm/s km/h km/min km/s m/h m/min m/s cm/min fph fps): ";
    cin>>yf;
    for (j=0; j<=9; j++)
        if (stricmp(yf,V[j])==0)
            vf=j;
    switch(vi)
    {
    case 0:
    {
        switch(vf)
        {
        case 1:
            rez=x*0.035999999712000005;
            break;
        case 2:
            rez=x*0.0005999999880000002;
            break;
        case 3:
            rez=x*0.00001;
            break;
        case 4:
            rez=x*35.99997120002304;
            break;
        case 5:
            rez=x*0.5999999880000003;
            break;
        case 6:
            rez=x*0.01;
            break;
        case 7:
            rez=x*59.9999880000024;
            break;
        case 8:
            rez=x*118.10977122137315;
            break;
        case 9:
            rez=x*0.03280839895013123;
            break;
        }
        break;
    }

    case 1:
    {
        switch(vf)
        {
        case 0:
            rez=x*27.777777999999998;
            break;
        case 2:
            rez=x*0.016666666466666667;
            break;
        case 3:
            rez=x*0.00027777777999999997;
            break;
        case 4:
            rez=x*999.9992080006334;
            break;
        case 5:
            rez=x*16.66666646666667;
            break;
        case 6:
            rez=x*0.27777778;
            break;
        case 7:
            rez=x*1666.6663466667305;
            break;
        case 8:
            rez=x*3280.827004618092;
            break;
        case 9:
            rez=x*0.9113444225721783;
            break;
        }
        break;
    }

    case 2:
    {
        switch(vf)
        {
        case 0:
            rez=x*1666.6667;
            break;
        case 1:
            rez=x*60.00000072;
            break;
        case 3:
            rez=x*0.016666667;
            break;
        case 4:
            rez=x*59999.95320003744;
            break;
        case 5:
            rez=x*1000;
            break;
        case 6:
            rez=x*16.666667;
            break;
        case 7:
            rez=x*99999.98200000361;
            break;
        case 8:
            rez=x*196849.62263928098;
            break;
        case 9:
            rez=x*54.68066601049868;
            break;
        }
        break;
    }

    case 3:
    {
        switch(vf)
        {
        case 0:
            rez=x*100000;
            break;
        case 1:
            rez=x*3599.9999712000003;
            break;
        case 2:
            rez=x*59.99999880000002;
            break;
        case 4:
            rez=x*3599997.1200023037;
            break;
        case 5:
            rez=x*59999.99880000002;
            break;
        case 6:
            rez=x*1000;
            break;
        case 7:
            rez=x*5999998.80000024;
            break;
        case 8:
            rez=x*11810977.122137316;
            break;
        case 9:
            rez=x*3280.839895013123;
            break;
        }
        break;
    }

    case 4:
    {
        switch(vf)
        {
        case 0:
            rez=x*0.027777800000000002;
            break;
        case 1:
            rez=x*0.0010000007919999938;
            break;
        case 2:
            rez=x*0.000016666679666666405;
            break;
        case 3:
            rez=x*2.77778*pow(10,-7);
            break;
        case 5:
            rez=x*0.016666679666666406;
            break;
        case 6:
            rez=x*0.000277778;
            break;
        case 7:
            rez=x*1.6666676666664668;
            break;
        case 8:
            rez=x*3.2808296030330593;
            break;
        case 9:
            rez=x*0.0009113451443569554;
            break;
        }
        break;
    }

    case 5:
    {
        switch(vf)
        {
        case 0:
            rez=x*1.6666667;
            break;
        case 1:
            rez=x*0.060000000719999995;
            break;
        case 2:
            rez=x*0.001;
            break;
        case 3:
            rez=x*0.000016666667;
            break;
        case 4:
            rez=x*59.99995320003744;
            break;
        case 6:
            rez=x*0.016666667;
            break;
        case 7:
            rez=x*99.9999820000036;
            break;
        case 8:
            rez=x*196.84962263928097;
            break;
        case 9:
            rez=x*0.05468066601049868;
            break;
        }
        break;
    }
    case 6:
    {
        switch(vf)
        {
        case 0:
            rez=x*100;
            break;
        case 1:
            rez=x*3.5999999712000004;
            break;
        case 2:
            rez=x*0.05999999880000002;
            break;
        case 3:
            rez=x*0.001;
            break;
        case 4:
            rez=x*3599.9971200023037;
            break;
        case 5:
            rez=x*59.99999880000003;
            break;
        case 7:
            rez=x*5999.99880000024;
            break;
        case 8:
            rez=x*11810.977122137316;
            break;
        case 9:
            rez=x*3.280839895013123;
            break;
        }
        break;
    }
    case 7:
    {
        switch (vf)
        {
        case 0:
            rez=x*0.016666669999999998;
            break;
        case 1:
            rez=x*0.0006000001151999991;
            break;
        case 2:
            rez=x*0.000010000001799999962;
            break;
        case 3:
            rez=x*1.666667e-7;
            break;
        case 4:
            rez=x*0.5999996400002879;
            break;
        case 5:
            rez=x*0.010000001799999964;
            break;
        case 6:
            rez=x*0.0001666667;
            break;
        case 8:
            rez=x*1.968496580722123;
            break;
        case 9:
            rez=x*0.0005468067585301837;
            break;
        }
        break;
    }
    case 8:
    {
        switch (vf)
        {
        case 0:
            rez=x*0.008466699999999999;
            break;
        case 1:
            rez=x*0.0003048011975615904;
            break;
        case 2:
            rez=x*0.000005080019898399602;
            break;
        case 3:
            rez=x*8.4667e-8;
            break;
        case 4:
            rez=x*0.304800956159235;
            break;
        case 5:
            rez=x*0.005080019898399602;
            break;
        case 6:
            rez=x*0.000084667;
            break;
        case 7:
            rez=x*0.5080018983996203;
            break;
        case 9:
            rez=x*0.00027777887139107606;
            break;
        }
        break;
    }
    case 9:
    {
        switch (vf)
        {
        case 0:
            rez=x*30.48;
            break;
        case 1:
            rez=x*1.0972799912217601;
            break;
        case 2:
            rez=x*0.018287999634240007;
            break;
        case 3:
            rez=x*0.00030480000000000004;
            break;
        case 4:
            rez=x*1097.2791221767022;
            break;
        case 5:
            rez=x*18.28799963424001;
            break;
        case 6:
            rez=x*0.3048;
            break;
        case 7:
            rez=x*1828.7996342400734;
            break;
        case 8:
            rez=x*3599.985826827454;
            break;
        }
    }
    }
    cout<<rez<<" "<<V[vf]<<endl;
}
void citdens()
{
    for (int j=0; j<=9; j++)
        finDens>>D[j];
}
void densitate(float x)
{
    char y[7], yf[7];
    int di, df, j;
    double rez;
    cout<<"Introduceti densitatea initiala: ";
    cin>>x;
    cout<<"Introduceti unitatea de masura initiala (g/cm^3 g/m^3 g/mm^3 kg/cm^3 kg/m^3 mg/cm^3 t/m^3 mg/m^3 g/l g/ml): ";
    cin>>y;
    for (j=0; j<=9; j++)
        if (stricmp(y,D[j])==0)
            di=j;
    cout<<"Introduceti unitatea de masura finala (g/cm^3 g/m^3 g/mm^3 kg/cm^3 kg/m^3 mg/cm^3 t/m^3 mg/m^3 g/l g/ml): ";
    cin>>yf;
    for (j=0; j<=9; j++)
        if (stricmp(yf,D[j])==0)
            df=j;
    switch(di)
    {
    case 0:
    {
        switch(df)
        {
        case 1:
            rez=x*1000000;
            break;
        case 2:
            rez=x*0.001;
            break;
        case 3:
            rez=x*0.001;
            break;
        case 4:
            rez=x*1000;
            break;
        case 5:
            rez=x*1000;
            break;
        case 6:
            rez=x;
            break;
        case 7:
            rez=x*1000000000;
            break;
        case 8:
            rez=x*1000;
            break;
        case 9:
            rez=x;
            break;
        }
        break;
    }

    case 1:
    {
        switch(df)
        {
        case 0:
            rez=x*0.000001;
            break;
        case 2:
            rez=x*pow(10,-9);
            break;
        case 3:
            rez=x*pow(10,-9);
            break;
        case 4:
            rez=x*0.001;
            break;
        case 5:
            rez=x*0.001;
            break;
        case 6:
            rez=x*0.000001;
            break;
        case 7:
            rez=x*1000;
            break;
        case 8:
            rez=x*0.001;
            break;
        case 9:
            rez=x*0.000001;
            break;
        }
        break;
    }

    case 2:
    {
        switch(df)
        {
        case 0:
            rez=x*1000;
            break;
        case 1:
            rez=x*pow(10,9);
            break;
        case 3:
            rez=x;
            break;
        case 4:
            rez=x*1000000;
            break;
        case 5:
            rez=x*1000000;
            break;
        case 6:
            rez=x*1000;
            break;
        case 7:
            rez=x*1000000000000;
            break;
        case 8:
            rez=x*1000000;
            break;
        case 9:
            rez=x*1000;
            break;
        }
        break;
    }

    case 3:
    {
        switch(df)
        {
        case 0:
            rez=x*1000;
            break;
        case 1:
            rez=x*pow(10,9);
            break;
        case 2:
            rez=x;
            break;
        case 4:
            rez=x*1000000;
            break;
        case 5:
            rez=x*1000000;
            break;
        case 6:
            rez=x*1000;
            break;
        case 7:
            rez=x*1000000000000;
            break;
        case 8:
            rez=x*1000000;
            break;
        case 9:
            rez=x*1000;
            break;
        }
        break;
    }

    case 4:
    {
        switch(df)
        {
        case 0:
            rez=x*0.001;
            break;
        case 1:
            rez=x*1000;
            break;
        case 2:
            rez=x*pow(10,-6);
            break;
        case 3:
            rez=x*pow(10,-6);
            break;
        case 5:
            rez=x;
            break;
        case 6:
            rez=x*0.001;
            break;
        case 7:
            rez=x*1000000;
            break;
        case 8:
            rez=x;
            break;
        case 9:
            rez=x*0.001;
            break;
        }
        break;
    }

    case 5:
    {
        switch(df)
        {
        case 0:
            rez=x*0.001;
            break;
        case 1:
            rez=x*1000;
            break;
        case 2:
            rez=x*pow(10,-6);
            break;
        case 3:
            rez=x*pow(10,-6);
            break;
        case 4:
            rez=x;
            break;
        case 6:
            rez=x*0.001;
            break;
        case 7:
            rez=x*1000000;
            break;
        case 8:
            rez=x;
            break;
        case 9:
            rez=x*0.001;
            break;
        }
        break;
    }
    case 6:
    {
        switch (df)
        {
        case 0:
            rez=x;
            break;
        case 1:
            rez=x*1000000;
            break;
        case 2:
            rez=x*0.001;
            break;
        case 3:
            rez=x*0.001;
            break;
        case 4:
            rez=x*1000;
            break;
        case 5:
            rez=x*1000;
            break;
        case 7:
            rez=x*1000000000;
            break;
        case 8:
            rez=x*1000;
            break;
        case 9:
            rez=x;
            break;
        }
        break;
    }
    case 7:
    {
        switch (df)
        {
        case 0:
            rez=x*9.999999999999999*2.71;
            break;
        case 1:
            rez=x*0.001;
            break;
        case 2:
            rez=x*2.71;
            break;
        case 3:
            rez=x*2.71;
            break;
        case 4:
            rez=x*0.000001;
            break;
        case 5:
            rez=x*0.000001;
            break;
        case 6:
            rez=x*9.999999999999999*2.71;
            break;
        case 8:
            rez=x*0.000001;
            break;
        case 9:
            rez=x*9.999999999999999*2.71;
            break;
        }
        break;
    }
    case 8:
    {
        switch (df)
        {
        case 0:
            rez=x*0.001;
            break;
        case 1:
            rez=x*1000;
            break;
        case 2:
            rez=x*0.000001;
            break;
        case 3:
            rez=x*0.000001;
            break;
        case 4:
            rez=x;
            break;
        case 5:
            rez=x;
            break;
        case 6:
            rez=x*0.001;
            break;
        case 7:
            rez=x*1000000;
            break;
        case 9:
            rez=x*0.001;
            break;
        }
        break;
    }
    case 9:
    {
        switch (df)
        {
        case 0:
            rez=x;
            break;
        case 1:
            rez=x*1000000;
            break;
        case 2:
            rez=x*0.001;
            break;
        case 3:
            rez=x*0.001;
            break;
        case 4:
            rez=x*1000;
            break;
        case 5:
            rez=x*1000;
            break;
        case 6:
            rez=x;
            break;
        case 7:
            rez=x*1000000000;
            break;
        case 8:
            rez=x*1000;
            break;
        }
        break;
    }
    }
    cout<<rez<<" "<<D[df]<<endl;
}
void citenerg()
{
    for (int j=0; j<=6; j++)
        finE>>E[j];
}
void energie(double x)
{
    char y[5], yf[5];
    double rez;
    int j, ei, ef;
    cout<<"Introduceti energia initiala: ";
    cin>>x;
    cout<<"Introduceti unitatea de masura initiala (cal/kcal/j/kj/kwh/wh/ws): ";
    cin>>y;
    for (j=0; j<=6; j++)
        if (stricmp(y,E[j])==0)
            ei=j;
    cout<<"Introduceti unitatea de masura finala (cal/kcal/j/kj/kwh/wh/ws): ";
    cin>>yf;
    for (j=0; j<=6; j++)
        if (stricmp(yf,E[j])==0)
            ef=j;
    switch(ei)
    {
    case 0:
    {
        switch(ef)
        {
        case 1:
            rez=x*0.001;
            break;
        case 2:
            rez=x*4.1868;
            break;
        case 3:
            rez=x*0.0041868;
            break;
        case 4:
            rez=x*0.000001163;
            break;
        case 5:
            rez=x*0.001163;
            break;
        case 6:
            rez=x*4.1868;
            break;
        }
        break;
    }
    case 1:
    {
        switch(ef)
        {
        case 0:
            rez=x*1000;
            break;
        case 2:
            rez=x*4186.8;
            break;
        case 3:
            rez=x*4.1868;
            break;
        case 4:
            rez=x*0.001163;
            break;
        case 5:
            rez=x*1.163;
            break;
        case 6:
            rez=x*4186.8;
            break;
        }
        break;
    }
    case 2:
    {
        switch(ef)
        {
        case 0:
            rez=x*0.23884589662749595;
            break;
        case 1:
            rez=x*0.00023884589662749592;
            break;
        case 3:
            rez=x*0.001;
            break;
        case 4:
            rez=x*2.7777777777777776*pow(10,-7);
            break;
        case 5:
            rez=x*0.0002777777777777778;
            break;
        case 6:
            rez=x;
            break;
        }
        break;
    }
    case 3:
    {
        switch(ef)
        {
        case 0:
            rez=x*238.84589662749596;
            break;
        case 1:
            rez=x*0.23884589662749592;
            break;
        case 2:
            rez=x*1000;
            break;
        case 4:
            rez=x*0.0002777777777777778;
            break;
        case 5:
            rez=x*0.2777777777777778;
            break;
        case 6:
            rez=x*1000;
            break;
        }
        break;
    }
    case 4:
    {
        switch(ef)
        {
        case 0:
            rez=x*859845.2278589854;
            break;
        case 1:
            rez=x*859.8452278589854;
            break;
        case 2:
            rez=x*3600000;
            break;
        case 3:
            rez=x*3600;
            break;
        case 5:
            rez=x*1000;
            break;
        case 6:
            rez=x*3600000;
            break;
        }
        break;
    }
    case 5:
    {
        switch(ef)
        {
        case 0:
            rez=x*859.8452278589854;
            break;
        case 1:
            rez=x*0.8598452278589853;
            break;
        case 2:
            rez=x*3600;
            break;
        case 3:
            rez=x*3.6;
            break;
        case 4:
            rez=x*0.001;
            break;
        case 5:
            rez=x*3600;
            break;
        }
        break;
    }
    case 6:
    {
        switch(ef)
        {
        case 0:
            rez=x*0.23884589662749595;
            break;
        case 1:
            rez=x*0.00023884589662749592;
            break;
        case 2:
            rez=x;
            break;
        case 3:
            rez=x*0.001;
            break;
        case 4:
            rez=x*2.7777777777777776*pow(10,-7);
            break;
        case 5:
            rez=x*0.0002777777777777778;
            break;
        }
        break;
    }
    }
    cout<<rez<<" "<<E[ef]<<endl;
}
void citirecomb()
{
    for (int j=0; j<=7; j++)
        finComb>>COMB[j];
}
void combustibil (double x)
{
    char y[12], yf[12];
    double rez;
    int ci, cf, j;
    cout<<"Introduceti cantitatea de combustibil initiala: ";
    cin>>x;
    cout<<"Introduceti unitatea de masura initiala (l/100km km/l mi/gal gal/100mi ukmi/gal ukgal/100mi mi/l l/100mi): ";
    cin>>y;
    for (j=0; j<=7; j++)
        if (stricmp(y, COMB[j])==0)
            ci=j;
    cout<<"Introduceti unitatea de masura finala (l/100km km/l mi/gal gal/100mi ukmi/gal ukgal/100mi mi/l l/100mi): ";
    cin>>yf;
    for (j=0; j<=7; j++)
        if (stricmp(yf, COMB[j])==0)
            cf=j;
    switch (ci)
    {
    case 0:
    {
        switch (cf)
        {
        case 1:
            rez=100/x;
            break;
        case 2:
            rez=235.2/x;
            break;
        case 3:
            rez=x*0.4251;
            break;
        case 4:
            rez=282.5/x;
            break;
        case 5:
            rez=x*0.354;
            break;
        case 6:
            rez=62,14/x;
            break;
        case 7:
            rez=x*1.609;
            break;
        }
        break;
    }
    case 1:
    {
        switch (cf)
        {
        case 0:
            rez=100/x;
            break;
        case 2:
            rez=x*2.352;
            break;
        case 3:
            rez=42.51/x;
            break;
        case 4:
            rez=x*2.825;
            break;
        case 5:
            rez=35.4/x;
            break;
        case 6:
            rez=x*0.6214;
            break;
        case 7:
            rez=160.9/x;
            break;
        }
        break;
    }
    case 2:
    {
        switch (cf)
        {
        case 0:
            rez=235.2/x;
            break;
        case 1:
            rez=x*0.4251;
            break;
        case 3:
            rez=100/x;
            break;
        case 4:
            rez=x*1.201;
            break;
        case 5:
            rez=83.27/x;
            break;
        case 6:
            rez=x*0.2642;
            break;
        case 7:
            rez=378.5/x;
            break;
        }
        break;
    }
    case 3:
    {
        switch (cf)
        {
        case 0:
            rez=x*2.352;
            break;
        case 1:
            rez=42.51/x;
            break;
        case 2:
            rez=100/x;
            break;
        case 4:
            rez=120.1/x;
            break;
        case 5:
            rez=x*0.8327;
            break;
        case 6:
            rez=26.42/x;
            break;
        case 7:
            rez=x*3.785;
            break;
        }
        break;
    }
    case 4:
    {
        switch (cf)
        {
        case 0:
            rez=282.5/x;
            break;
        case 1:
            rez=x*0.354;
            break;
        case 2:
            rez=x*0.8327;
            break;
        case 3:
            rez=120.1/x;
            break;
        case 5:
            rez=100/x;
            break;
        case 6:
            rez=x*0.22;
            break;
        case 7:
            rez=454.6/x;
            break;
        }
        break;
    }
    case 5:
    {
        switch (cf)
        {
        case 0:
            rez=x*2.825;
            break;
        case 1:
            rez=35.4/x;
            break;
        case 2:
            rez=83.27/x;
            break;
        case 3:
            rez=x*1.201;
            break;
        case 4:
            rez=100/x;
            break;
        case 6:
            rez=22/x;
            break;
        case 7:
            rez=x*4.546;
            break;
        }
        break;
    }
    case 6:
    {
        switch (cf)
        {
        case 0:
            rez=62.14/x;
            break;
        case 1:
            rez=x*1.609;
            break;
        case 2:
            rez=x*3.785;
            break;
        case 3:
            rez=26.42/x;
            break;
        case 4:
            rez=x*4.546;
            break;
        case 5:
            rez=22/x;
            break;
        case 7:
            rez=100/x;
            break;
        }
        break;
    }
    case 7:
    {
        switch (cf)
        {
        case 0:
            rez=x*0.6214;
            break;
        case 1:
            rez=160.9/x;
            break;
        case 2:
            rez=378.5/x;
            break;
        case 3:
            rez=x*0.2642;
            break;
        case 4:
            rez=454.6/x;
            break;
        case 5:
            rez=x*0.22;
            break;
        case 6:
            rez=100/x;
            break;
        }
        break;
    }
    }
    cout<<rez<<" "<<COMB[cf]<<endl;
}

void meniu (int o)
{
//	int opt;

//	cin>>opt;
    switch (o)
    {
    case 1:
        citirel();
        lungime(x);
        break;
    case 2:
        citirea();
        arie(x);
        break;
    case 3:
        citirev();
        volum(x);
        break;
    case 4:
        cittemp();
        temperatura(x);
        break;

    case 5:
        cittimp();
        timp(x);
        break;

    case 6:
        citirevit();
        viteza(x);
        break;
    case 7:
        citmasa();
        masa(x);
        break;

    case 8:
        citpres();
        presiune(x);
        break;

    case 9:
        citdens();
        densitate(x);
        break;

    case 10:
        citenerg();
        energie(x);

    case 11:
        citirecomb();
        combustibil(x);

        //default:exit;
    }
}

int main()
{

    int opt;
    cout<<endl;
    cout<<"1. Conversie lungime "<<endl;
    cout<<"2. Conversie arie "<<endl;
    cout<<"3. Conversie volum "<<endl;
    cout<<"4. Conversie temperatura "<<endl;
    cout<<"5. Conversie timp "<<endl;
    cout<<"6. Conversie viteza "<<endl;
    cout<<"7. Conversie masa "<<endl;
    cout<<"8. Conversie presiune "<<endl;
    cout<<"9. Conversie densitate "<<endl;
    cout<<"10. Conversie energie "<<endl;
    cout<<"11. Conversie combustibil "<<endl;
    cout<<"0. Iesire "<<endl;
    cout<<endl;
    do
    {
        cout<<"Introduceti optiunea: ";
        cin>> opt;
        meniu(opt);
    }
    while (opt);
    return 0;
}




