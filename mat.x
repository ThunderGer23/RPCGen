struct r_times_X
{
	int X <100>;
	int X_size;
	float r;
};

struct rX
{
	float prod <100>;
};

program MAT_PROG
{
	version MAT_VERS
	{		
		rX product(r_times_X) = 3;
	} = 1;
} = 0x23450001;
