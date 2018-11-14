`timescale 1ns/10ps

module testmux;
	//inputs: at the master file, inputs must be registers
	reg a, b, s;
	//output: this must be a wire!
	wire out;
	//type_of_gate, name_your_gate(outputs, inputs)
	mux2to1 myLovelyLadyMux(a, b, s, out);
	
	initial //this initiates the sim, and you get to orchestrate it
	begin
		//actual simulation part
		$dumpfile("testmux.vcd");
		$dumpvars(0,testmux);
		a=0;
		b=1;
		s=0;
		#1; //pause
		a=1;
		#1; //another pause
		s=1;
		b=0;
		#3;
		a=0;
		$finish;
	end

endmodule
