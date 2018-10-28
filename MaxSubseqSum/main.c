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

/*ʱ�临�Ӷ�ΪO(n^3)*/
int MaxSubseqSum1(int a[], int n)
{
    int ThisSum, MaxSum = 0;
    int front, rear;    //���������������
    int i, j, k;

    for(i = 0; i < n; i++){             //i��������˵�λ��
        for(j = i; j < n; j++){         //j�������Ҷ˵�λ��
            ThisSum = 0;                //ThisSum������a[i]��a[j]�ĺ�
            for(k = i; k <= j; k++){     //k����a[i]��a[j]�ı�������i�̶�ʱ������ÿ�δ�a[i]��ʼ�ۼӣ�
                                        //ֻ������һ��a[i]��a[j]�͵Ļ����ϼ����µ�a[j]����Ϊ�µ����к�
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

/*ʱ�临�Ӷ�ΪO(n^2)*/
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

/*�����㷨��ʱ�临�Ӷ�ΪO(NlogN)*/
int MaxSubseqSum3(int a[], int left, int right)
{
    int MaxSum;
    int MaxLeftSum, MaxRightSum, MaxCenterSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int center, i;

    if(left == right){      //�ݹ����ֹ������������ֻ��һ������
        if(a[left] > 0)
            return a[left];
        else
            return 0;
    }

    /*���֡�*/
    center = (left + right) / 2;    //printf("center:%d\n", center);
    MaxLeftSum = MaxSubseqSum3(a, left, center);    //printf("LeftSum:%d\n", MaxLeftSum);
    MaxRightSum = MaxSubseqSum3(a, center + 1, right);  //printf("RightSum:%d\n", MaxRightSum);

    /*���ֽ��ߵ�������к�*/
    MaxLeftBorderSum = MaxRightBorderSum = 0;
    LeftBorderSum = RightBorderSum = 0;
    for(i = center; i >= left; i--){    //���м������ɨ��
        LeftBorderSum += a[i];
        if(LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }
    for(i = center + 1; i <= right; i++){
        RightBorderSum += a[i];         //���м�����ɨ��
        if(RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }
    MaxCenterSum = MaxLeftBorderSum + MaxRightBorderSum;    //printf("CenterSum:%d\n\n", MaxCenterSum);

    /*���Ρ�*/
    MaxSum = Max3(MaxLeftSum, MaxRightSum, MaxCenterSum);

    return MaxSum;
}

/*���������е������*/
int Max3(int a, int b, int c)
{
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

/*���ߴ���ʱ�临�Ӷ�ΪO(n)*/
/*�����ߡ�ָÿ����һ�����ݾͽ��м�ʱ�������κ�һ���ط���ֹ���룬�㷨������ȷ�ظ�����ǰ�Ľ�*/
int MaxSubseqSum4(int a[], int n)
{
    int ThisSum, MaxSum;

    ThisSum = MaxSum = 0;
    for(int i = 0; i < n; i++){
        ThisSum += a[i];
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)    //����ǰ�����к�Ϊ��������һ�����ú�������к��С������֮
            ThisSum = 0;
    }
    return MaxSum;
}
