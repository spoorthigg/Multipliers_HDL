//Code for Wallace 4x4:
module wallace44(
    input [3:0] a,
    input [3:0] b,
    output [7:0] sum
    );
    wire p0, p1 , c1, w1, w2;
    integer i;
    reg temp;
    reg [2:0] sumtemp1, sumtemp2 , sumtemp3;
    reg [2:0] p2 , p3 , p4;
    wire [2:0] p5 , p6;
    wire [1:0] pt;

   assign p0 = a[0]&b[0];
   assign w1 = a[0]&b[1];
   assign w2 = a[1]&b[0];
   
   halfadder ha1( w1 , w2 , p1 , c1 );
   
    always@(*)
    begin
    sumtemp1 = 2'b0;  sumtemp2 = 2'b0;  sumtemp3 = 2'b0; 
    for(i = 0; i<3; i = i+1 )
    begin
        temp = a[i]&b[2-i];
            sumtemp1 = sumtemp1 + temp;
      end
        p2 = sumtemp1 + c1; // msb is carry for next stage and lsb is the answer
       
        
        for(i = 0; i<4; i = i+1 )
        begin
            temp = a[i]&b[3-i];
            sumtemp2 = sumtemp2 + temp;
        end
        p3 = sumtemp2 + p2[2:1];
     
         for(i = 1; i<4; i = i+1 )
         begin
            temp = a[i]&b[4-i];
            sumtemp3 = sumtemp3 + temp;
         end
         p4 = sumtemp3 + p3[2:1];
     
     end
     
    assign pt = p4[2:1];
    assign p5 =  (a[2]&b[3]) + (a[3]&b[2]) + pt;
    assign p6 = (a[3]&b[3]) + p5[2:1];      
    assign sum = {p6 , p5[0] , p4[0] , p3[0], p2[0] , p1, p0 };      
endmodule

// Half Adder Code for Wallace
module halfadder(
    input a,
    input b,
    output sum,
    output cout
    );
    assign sum = a^b;
    assign cout = a&b;
endmodule

//Full Adder Code for Wallace
module fulladder(
    input c,
    input a,
    input b,
    output sum, 
    output cout
    );
    assign sum = a^b^c;
    assign cout = (a&b)|(b&c)|(c&a);
     
endmodule
