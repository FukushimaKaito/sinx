/*------------------------------------------------
課題1b	sinxの近似

2014/05/21
4I31	福嶋開人
------------------------------------------------*/

#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793		//円周率を定義した

/*		階乗を求める関数(再帰で動かすようにしてある)
			引数double	戻り値double					*/
double kaijo(double n){
	if (n > 0){
		return n*kaijo(n - 1);//再帰処理
	}
	else{
		return 1;//関数から抜け出す
	}
}

/*	main関数	*/
int main(void)
{
	//sum:答えを足していく	x:入力値	a:(-1)^n	b:1/(2n+1)!	c:x^(2n+1)
	double sum = 0.0, x = 1.0, a = 1.0, b = 1.0, c = 1.0;

	printf("sin x を冪級数を用いて求めるプログラム\n\n");
	printf("xを入力してください[degree]：");		//入力値は°[degree]にした
	scanf_s("%lf", &x);

	x = x * PI /180.0;			//計算中は[radian]でするから変換した(PIは円周率でヘッダーに定義した)
	printf("実際の値 : %5.10e\n", sin(x));		//実際の計算値を表示する．これと相対誤差をとっていく

	for (int n = 0; fabs(sin(x) - sum) >= 0.00000001; n++)//相対誤差が10^8になるとループから抜ける	fabsは絶対値を求める
	{
		a = pow(-1.0, n);				//(-1)^n
		b = 1.0 / kaijo(2.0 * n + 1.0);	//b:1/(2n+1)!
		c = pow(x, 2.0 * n + 1.0);		//c:x^(2n+1)
		sum = sum + a*b*c;				//Σ

		printf("第%d項の値 : %5.10e	近似値 : %5.10e\n", n + 1, a*b*c, sum);//実行途中経過
		printf("相対誤差 : %5.10e\n\n", fabs(sin(x) - sum));			//途中の相対誤差
	}

	printf("近似値\n%26.18e\n", sum);	//最終結果表示

	getch();							//すぐに実行結果が消えないようにしただけ

	return 0;
}