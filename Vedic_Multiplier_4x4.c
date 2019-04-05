//Code for Vedic 4x4:
module vedic44(
    input [3:0] a,
    input [3:0] b,
    output [8:0] sum
    );
    wire [5:0] w2 ,w3 ,w4;
    wire [3:0] w1, temps1 ,  temps2 , temps4  ,temps5; 
    wire [4:0] temps3;
    wire [6:0] temps6, w5, temps7;
    
    vedic22 v1(a[1:0], b[1:0], temps1); // multiplication of the lsbs
    
    assign w1 = {2'b00, temps1[3:2]};
    
    vedic22 v2(a[3:2], b[1:0], temps2);
    adder ad1(temps2, w1, temps3, 1'b0);
    
    vedic22 v3(a[1:0] , b[3:2] , temps4); // multiplication of the lsbs
    vedic22 v4(a[3:2] , b[3:2] , temps5);
    
    assign w2 = { 2'b0, temps4};
    assign w3  = {temps5 , 2'b0};
    
    adder6 ad6_1( w3 , w2 , temps6);
    assign w4 = {1'b0, temps3} ;
    
    adder6 ad6_2(temps6[5:0] ,w4 ,temps7 ); 
    assign sum = { temps7, temps1[1:0]};    
endmodule

//Code for Vedic 2x2
module vedic22(
    input [1:0] a,
    input [1:0] b,
    output [3:0] sum
    );
    wire w1, w2, w3, w4;
    and a1(sum[0], a[0], b[0]);
    and a2(w1, a[1], b[0]);
    and a3(w2, a[0], b[1]);
    and a4(w4, a[1], b[1]);
    and a5(w3, w1, w2);
    and a6(sum[3], w3, w4);
    xor x1(sum[1], w1, w2);
    xor x2(sum[2], w3, w4);
endmodule

//Code for 6 bit adder
module adder6(
    input [5:0] a,
    input [5:0] b,
    output [6:0] sum
    );
assign sum = a+b;   
endmodule
