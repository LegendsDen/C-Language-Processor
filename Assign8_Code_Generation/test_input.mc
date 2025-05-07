integer f=5;
float k=9.1;
integer w[10];
void func(integer f,float h);
integer a=*w;
integer main() begin
    integer a = 5, b = 10;
    float x = 3.14;
    integer arr[5];
    if (a < b) begin
        arr[0] = a + b;
        arr[1]=a+b;
    end else begin
        arr[0] = a - b;
    end
    integer i=0;
    
    while(i<5)begin
        arr[i] = arr[i-1] * i;
        i=i+1;
    end
    return arr[4];
end