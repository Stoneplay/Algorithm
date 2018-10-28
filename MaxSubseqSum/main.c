#include <stdio.h>
#include <stdlib.h>

#define num 4

int MaxSubseqSum1(int a[], int n);
int MaxSubseqSum2(int a[], int n);
int MaxSubseqSum3(int a[], int left, int right);
int Max3(int a, int b, int c);
int MaxSubseqSum4(int a[], int n);

int main()
{
    int a[num] = {4, -3 ,5, -2};
    int MaxSum1, MaxSum2, MaxSum3, MaxSum4;

    MaxSum1 = MaxSubseqSum1(a, num);
    printf("The MaxSum1 is %d.\n\n", MaxSum1);

    MaxSum2 = MaxSubseqSum2(a, num);
    printf("The MaxSum2 is %d.\n\n", MaxSum2);

    MaxSum3 = MaxSubseqSum3(a, 0, num - 1);
    printf("The MaxSum3 is %d.\n\n", MaxSum3);

    MaxSum4 = MaxSubseqSum4(a, num);
    printf("The MaxSum4 is %d.\n\n", MaxSum4);

    return 0;
}

/*时间复杂度为O(n^3)*/
int MaxSubseqSum1(int a[], int n)
{
    int ThisSum, MaxSum = 0;
    int front, rear;    //用于输出最大和子列
    int i, j, k;

    for(i = 0; i < n; i++){             //i是子列左端的位置
        for(j = i; j < n; j++){         //j是子列右端的位置
            ThisSum = 0;                //ThisSum是子列a[i]到a[j]的和
            for(k = i; k <= j; k++){     //k用于a[i]到a[j]的遍历。当i固定时，不必每次从a[i]开始累加，
                                        //只需在上一次a[i]到a[j]和的基础上加上新的a[j]，即为新的子列和
                ThisSum += a[k];
                if(ThisSum > MaxSum){
                    MaxSum = ThisSum;
                    front = i;
                    rear = j;
                }
            }
        }
    }

    printf("The max sequence is : ");
    for(int q = front; q <= rear; q++)
        printf("%-3d", a[q]);
    printf("\n");
    return MaxSum;
}

/*时间复杂度为O(n^2)*/
int MaxSubseqSum2(int a[], int n)
{
    int ThisSum, MaxSum = 0;
    int front, rear;
    int i,j;

    for(i = 0; i < n; i++){
        ThisSum = 0;
        for(j = i; j < n; j++){
            ThisSum += a[j];
            if(ThisSum > MaxSum){
                MaxSum = ThisSum;
                front = i;
                rear = j;
            }
        }
    }

    printf("The max sequence is : ");
    for(int q = front; q <= rear; q++)
        printf("%-3d", a[q]);
    printf("\n");
    return MaxSum;
}

/*分治算法，时间复杂度为O(NlogN)*/
int MaxSubseqSum3(int a[], int left, int right)
{
    int MaxSum;
    int MaxLeftSum, MaxRightSum, MaxCenterSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int center, i;

    if(left == right){      //递归的终止条件：子列中只有一个数字
        if(a[left] > 0)
            return a[left];
        else
            return 0;
    }

    /*“分”*/
    center = (left + right) / 2;    //printf("center:%d\n", center);
    MaxLeftSum = MaxSubseqSum3(a, left, center);    //printf("LeftSum:%d\n", MaxLeftSum);
    MaxRightSum = MaxSubseqSum3(a, center + 1, right);  //printf("RightSum:%d\n", MaxRightSum);

    /*求跨分界线的最大子列和*/
    MaxLeftBorderSum = MaxRightBorderSum = 0;
    LeftBorderSum = RightBorderSum = 0;
    for(i = center; i >= left; i--){    //从中间向左边扫描
        LeftBorderSum += a[i];
        if(LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }
    for(i = center + 1; i <= right; i++){
        RightBorderSum += a[i];         //从中间向右扫描
        if(RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }
    MaxCenterSum = MaxLeftBorderSum + MaxRightBorderSum;    //printf("CenterSum:%d\n\n", MaxCenterSum);

    /*“治”*/
    MaxSum = Max3(MaxLeftSum, MaxRightSum, MaxCenterSum);

    return MaxSum;
}

/*求三个数中的最大数*/
int Max3(int a, int b, int c)
{
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

/*在线处理，时间复杂度为O(n)*/
/*“在线”指每输入一个数据就进行即时处理，在任何一个地方终止输入，算法都能正确地给出当前的解*/
int MaxSubseqSum4(int a[], int n)
{
    int ThisSum, MaxSum;

    ThisSum = MaxSum = 0;
    for(int i = 0; i < n; i++){
        ThisSum += a[i];
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)    //若当前的子列和为负数，则一定会让后面的子列后变小，抛弃之
            ThisSum = 0;
    }
    return MaxSum;
}
