
#include <string>
using namespace std;

#include <iostream>

int solution(string &A, string &B){
    int hhA = (A[0]-48)*10+(A[1]-48); 
    int mmA = (A[3]-48)*10+(A[4]-48); 
    int hhB = (B[0]-48)*10+(B[1]-48);
    int mmB = (B[3]-48)*10+(B[4]-48);
	
	//cout << hhA << "=hhA, " << mmA << "=mmA, " << hhB << "=hhB, " << mmB << "=mmB" << endl;
	
    if(60*hhA+mmA > 60*hhB+mmB){
        hhB += 24;
    }
    
    //cout << 60*hhA+mmA << "=60*hhA+mmA, " << 60*hhB+mmB << "=60*hhB+mmB, " << hhB << "=hhB" << endl;
	
    int running_sum=0;
    
    int starting_quarter = (mmA+14)/15;
    int finishing_quarter = mmB/15;
    
    bool CorrectingFactor = ( (finishing_quarter-starting_quarter)!=-1 | hhA!=hhB | mmA%15==0 | mmB%15==0 );
    
    /*
    if(finishing_quarter-starting_quarter==-1 && hhA==hhB && mmA%15!=0 && mmB%15!=0){
    	CorrectingFactor = 0;
	}else{
		CorrectingFactor = 1;
	}
	*/
	//cout << starting_quarter << "=starting_quarter, " << finishing_quarter << "=finishing_quarter, " << (finishing_quarter-starting_quarter==-1) << "=finishing_quarter-starting_quarter==1 "<< (hhA==hhB) << "=hhA==hhB "<< (mmA%15!=0) << "=mmA%15!=0 "<< (mmB%15!=0) << "=mmB%15!=0 " << CorrectingFactor << "=CorrectingFactor "  << endl;
    
    running_sum += (finishing_quarter-starting_quarter)*CorrectingFactor;
    running_sum += 4*(hhB-hhA);
	
    return running_sum;
}

/*

("01:50", "03:46")
("01:50", "03:45")
("01:50", "03:44")

("01:45", "03:44")
("01:30", "03:15")
("01:30", "03:00")
("01:15", "03:00")

("01:45", "03:45")
("01:30", "03:30")
("01:15", "03:15")
("01:00", "03:00")

("", "")

*/
#include <iostream>


int main(int argc, char** argv) {
	string A; 
	string B;
	
	A = "06:00";
	B = "08:10";
	cout << solution(A, B) << " 8" << endl;
	A = "01:50";
	B = "02:00";
	cout << solution(A, B) << " 0" << endl;
	A = "00:30";
	B = "00:15";
	cout << solution(A, B) << " 95" << endl;
	A = "00:30";
	B = "00:16";
	cout << solution(A, B) << " 95" << endl;
	
	A = "01:50";
	B = "01:50";
	cout << solution(A, B) << " 0" << endl;
	A = "01:50";
	B = "01:51";
	cout << solution(A, B) << " 0" << endl;
	
	A = "01:50";
	B = "01:30";
	cout << solution(A, B) << " 94" << endl;
	A = "01:50";
	B = "02:50";
	cout << solution(A, B) << " 3" << endl;
	A = "01:30";
	B = "02:30";
	cout << solution(A, B) << " 4" << endl;
	A = "02:50";
	B = "01:50";
	cout << solution(A, B) << " 91" << endl;
	A = "02:30";
	B = "01:50";
	cout << solution(A, B) << " 93" << endl;
	A = "02:50";
	B = "01:30";
	cout << solution(A, B) << " 90" << endl;
	
	return 0;
}

