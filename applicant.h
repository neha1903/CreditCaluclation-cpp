class applicant{

    //defining data members for storing applicant details
    string name, address;
    int age;
    int m_sal, h_loan, p_loan, no_chq_bounce;
    char own_house, spouse_working, dependent_parent;
    int company_tier;

public:

    // class function declaration
    void getdata(){
        system("cls");
        //gotoxy(4,1);
        cin.ignore(20, '\n');
        cout << "Name of the Applicant : " ;
        getline( cin, name);
        cout << "Age : ";
        cin >> age;
        /*cout << endl;
        cout << name << " " <<age;*/
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Address : ";
        getline (cin, address);
        cout << "Monthly Salary : " ;
        cin >> m_sal;
        cout << "Total Home Loan EMI : ";
        cin >> h_loan;
        cout << "Total Personal Loan EMI : ";
        cin >> p_loan;
        cout << "Number of Cheque Bounces in last Six Month : ";
        cin >> no_chq_bounce;
        cout << "Own House? (y or n) : ";
        cin >> own_house;
        cout << "Spouse Working? (y or n) : ";
        cin >> spouse_working;
        cout << "Dependent Parent? (y or n) : ";
        cin >> dependent_parent;
        cout << "Company Tier? (1, 2 or 3) : ";
        cin >> company_tier;
    }
    int calc_liability(){
        int score = 0;
        int liability=0;


        if(age > 22 && age <= 30){
            score += 2;
        }else{
            if(age > 30 && age <=35){
                score += 1;
            }
            else{
                score -= 1;
            }
        }

        liability = h_loan + p_loan;
        if(liability <= m_sal/4){
            score += 5;
        }
        else if(liability > m_sal/4 && liability <= m_sal/3){
            score += 3;
        }
        else if(liability >= m_sal/3 && liability <= m_sal/2){
            score += 1;
        }
        else if(liability > m_sal/2){
            score -= 1;
        }
        if(no_chq_bounce > 1){
            score -= 2;
        }
        else if(no_chq_bounce == 1){
            score -= 1;
        }
        else if(no_chq_bounce == 0){
            score += 1;
        }

        if(p_loan > h_loan){
            score -= 1;
        }else if(h_loan > p_loan){
            score += 1;
        }

        if(own_house == 'y'){
            score += 1;
        }
        if(spouse_working == 'y'){
            score += 1;
        }
        if(dependent_parent == 'y'){
        }else{
            score += 1;
        }

        if(company_tier == 1){
            score += 3;
        }
        else if(company_tier == 2){
            score += 2;
        }
        else{
            score += 1;
        }
        return score;
    }
    void display_score(){
        int sc = calc_liability();
        system("cls");
        if(sc > 9){
            cout << "The Applicant " << name << " is at low risk.\nCredit score = " << sc << "\nCredit can be given";
        }
        else{
            if(sc > 5 && sc <=9 ){
                cout << "The Applicant " << name << " is at average risk.\nCredit score = " << sc << "\nCredit can be given with due precaution.";
            }
            else{
                cout << "The Applicant " << name << " is at high risk.\nCredit score = " << sc << "\nCredit can not be given.";
            }

        }
        getch();
    }
};
