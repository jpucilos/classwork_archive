`timescale 1ns/10ps

module testHalfAdder;
	reg a, b;
	wire sum, carry;
	halfAdder myHalfAdder(a, b, carry, sum);
	
	initial
	begin
		$dumpfile("testHalfAdder.vcd");
		$dumpvars(0,testHalfAdder);
		a=0;
		b=1;
		#1;
		a=1;
		#1;
		b=0;
		#3;
		a=0;
		
		$finish;
	end

endmodule
