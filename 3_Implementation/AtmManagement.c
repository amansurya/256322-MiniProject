
/**
 * @file ATM MANAGEMENT SYSTEM
 * @author Mangu Aman Surya (amansurya919@gmail.com ; LTTS ID 256322)
 * @brief Program for ATM MANAGEMENT with features to withdraw amount, transfer amount within accounts, change the pin and check balance.
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atm.h"
typedef struct account_details
{
    double acc_no;    /**< ID of the Box */
    float pin;  /**< Length of the Box */
    float balance; /**< Breadth of the Box */
    
    //float height;  /**< Height of the Box */
    //float weight;  /**< Weight of the Box */
    //color_t color; /**< Colour of the Box */
} account_details;
double acno=0;// account number currently logged into
float pinenter; // pin entered  
int t,option; // t is the test condition variable and option is  what is selected to perform 
int ind; // index for database of accounts
int m; // condition  variable to enter the main menu after completing minimum of 1 transaction.
account_details *account_ptr = NULL;
account_details *account_array = NULL;
/** @enum error_t
 *  @brief This enum is a definition of errors
 */
typedef enum error_t
{
    SUCCESS = 0,    /**< Success */
    MEMORY_FAILURE, /**< Memory Allocation failure Full */
    ARRAY_FULL,     /**< Array is full */
    NULL_PTR,       /**< Error Code for Failure */

} error_t;

/** @enum color_t
 *  @brief This enum is a definition of colours
 */
//typedef enum color_t
//{
  //  RED = 0xFF, /**< Colour Code for RED */
    //BLUE,       /**< Colour Code for BLUE */
    //GREEN       /**< Colour Code for GREEN */
//} color_t;*/

/** @struct box_t
 *  @brief This structure is a definition of box and its attributes
 */


/**
 * @brief Creates an Array of box dynamically
 * @param[in] box_ptr   Pointer to the array of Boxes
 * @param[in] number_of_boxes Number of Boxes in Array
 * @return Pointer to the newly created Box Array
 */
account_details *create_array_of_accounts(const int number_of_accounts)
{
    return calloc(number_of_accounts, sizeof(account_details));
}

/**
 * @brief Adds a box to the end of the current array where ID is NULL
 * @param[in] number of acounts
 * @return memory allocated to accounts
 */
error_t add_account_at_end( const int array_size, const account_details *new_account)
{
    if (NULL == account_ptr)
    {
        return NULL_PTR;
    }
    for (int index = 0; index < array_size; index++)
    {
        if (0 != (account_ptr + index)->acc_no)
        {
            continue;
        }
        else
        {
            memcpy((account_ptr + index), new_account, sizeof(account_details));
            return SUCCESS;
        }
    }
    return ARRAY_FULL;
}

/**
 * @brief adds accounts at the end
 * @param[in] size of the array of account
 * @param[in] new account pointer
 * @return Success if passed array is not NULL
 */
/*error_t display_all( const int array_size)
{
    if (NULL == account_ptr)
    {
        return NULL_PTR;
    }
    for (int index = 0; index < array_size && (0 != (account_ptr + index)->acc_no); index++)
    {
        printf("acc_no = %lf \npin = %f  \nBalance = %f \n",
               (account_ptr + index)->acc_no,
               (account_ptr + index)->pin,
               (account_ptr + index)->balance);
        
    }
    return SUCCESS;
}


 * displaying the contents of the accounts
 */
int ARRAY_SIZE = 5;

// If not assigned with NULL, it becomes a wild pointer


// Initialize two box variables
account_details box1 = {1000000000001, 1111, 10000};
account_details box2 = {1000000000002, 2222, 50000};
account_details box3 = {1000000000003, 3333, 2000};
account_details box4 = {1000000000004, 4444, 500};
account_details box5 = {1000000000005, 5555, 100000};
void login();
void mainMenu();
void checkBalance();
void moneyTransaction();
void moneyWithdraw();
//void pinchange();
void (*fp)();

int main()
{
	/**-------------------------------------------------------Creation of array of accounts------------------------------------*/
    // Allocate memory to hold the boxes
    account_ptr = create_array_of_accounts(ARRAY_SIZE);

    /** Add a box to the array */
    add_account_at_end( ARRAY_SIZE, &box1);
    add_account_at_end( ARRAY_SIZE, &box2);
    add_account_at_end( ARRAY_SIZE, &box3);
    add_account_at_end(ARRAY_SIZE, &box4);
    add_account_at_end( ARRAY_SIZE, &box5);
    
    
    /** Display all the added boxes */
    //display_all( ARRAY_SIZE);

    // release the dynamically allocated memory
    //free(box_ptr);
    //account_ptr = NULL;
    /**-------------------------------------------------------------------------------------------------------------------------*/
    mainMenu();
    
    
    
}
void mainMenu(){
printf("******************Hello!*******************\n");
    printf("**********Welcome to ATM Banking***********\n\n");
    printf("****Please choose one of the options below****\n\n");
    printf("&lt; 1 >  Check Balance\n");
    printf("&lt; 2 >  pin change\n");
    printf("&lt; 3 >  Withdraw\n");
    printf("&lt; 4 >  Money transfer\n"); 
    printf("&lt; 5 >  Exit\n\n");
    t=0;
    double k;
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Your Selection:\t");
    scanf("%d", &option);
    
    if(option==1 || option==2 || option==3 || option==4){
		printf("Enter your Account Number ");
scanf("%lf",&k);
acno=k;

ind=0;
	for (int index=0; index < ARRAY_SIZE ; index++)
    {
        
        if(acno == ((account_ptr + index)->acc_no) ){
			printf("Please enter the pin number");
			scanf("%f",&pinenter);
			
			if(pinenter==((account_ptr + index)->pin)){
			t=1;
			ind=index;
			break;
			}
			else printf("pin number did not match");
			
		}
		
    }
   
    if(ind >= 0 && t==0){
	printf("no account number matched");
	}

	if(t==1){
		switch (option) {
            case 1:
             //system("CLS");
                fp=checkBalance;
                fp();
                break;
            case 2:
             //system("CLS");
             printf("switch pin change entered");
                float i=pinchange();
                if(i){
                ((account_ptr+ind)->pin)=i;
                printf("pin changed to : %f",((account_ptr+ind)->pin));
                printf("enter 1 to continue and make another transcation");
			}
			else {
			printf("new pin entered did not match.\n");
			printf("enter 1 to continue and make another transcation");
			
			}
scanf("%d",&m);
if(m==1)mainMenu();
                
                break;
            case 3:
             //system("CLS");
                fp=moneyWithdraw;
                fp();
                break;
			case 4:
             //system("CLS");
                fp=moneyTransaction;
                fp();
                break;
 
            default:
                
                break;
        }
	}
	
    
    /**
     * @brief function that displays all the functionalities it does. It has no parameters and no return values.
     **/
    
    
 
}
else {
	printf("no relevant option selected");
printf("enter 1 to continue and make another transcation");
scanf("%d",&m);
if(m==1)mainMenu();
}
}
void checkBalance(){
printf("Current balance in the account is : ");
printf("%f\n",(account_ptr+ind)->balance);
printf("enter 1 to continue and make another transcation");
scanf("%d",&m);
if(m==1)mainMenu();

}
/**
     * @brief function is called to check the balance in your account. It has no parameters and no return values.
     **/
/*void pinchange(){
float newpina;
float newpinb;
printf("entered pinchange function");
printf("enter new pin : ");
scanf(" %f", &newpina);
printf("\n enter new pin again : ");
scanf(" %f", &newpinb);
if(newpina==newpinb){
	(account_ptr+ind)->pin=newpina;
printf("pin changed successfully");
}
printf("enter 1 to continue and make another transcation");
scanf("%d",&m);
if(m==1)mainMenu();
}*/
/**
     * @brief function that is called to change the Personal Identification Number for a perticular account tow hich it is currently logged into. It has no parameters and no return values.
     **/
void moneyWithdraw(){
	float amt;
	printf("enter amount to be withdrawn :");
	scanf(" %f",&amt);
	if(((account_ptr+ind)->balance)>=amt){
		((account_ptr+ind)->balance)=((account_ptr+ind)->balance)-amt;
	
	printf("amount debited successfully and remaining balance is : %f\n",((account_ptr+ind)->balance));
	
}
else{
	printf("insufficient funds\n");
}
printf("enter 1 to continue and make another transcation");
scanf("%d",&m);
if(m==1)mainMenu();
}
/**
     * @brief function that is used to withdraw a perticular amount from  your account. It has no parameters and no return values.
     **/
void moneyTransaction(){
	double acnum;
	float amt;
	printf("enter account number to tranfer the amount :");
scanf("%lf", &acnum);
printf("enter amount to be transferred :");
scanf(" %f", &amt);

	if(((account_ptr+ind)->balance) >= amt){
		
		((account_ptr+ind)->balance)=((account_ptr+ind)->balance)-amt;
		printf("amount debited");
		printf("balance is : %f", ((account_ptr+ind)->balance));
	
	for(int index=0; index< ARRAY_SIZE ; index++)
    {
		
      if(acnum == ((account_ptr + index)->acc_no) ){
			((account_ptr+index)->balance)=((account_ptr+index)->balance)+amt;
			printf("amount transfered");
			break;
			}
	}
	}
	else{
	printf("insufficient funds\n");
	}
	printf("enter 1 to continue and make another transcation");
scanf("%d",&m);
if(m==1)
{
	fp=mainMenu;
	fp();
	}
}
/**
     * @brief function that is called to transfer a certain amount from the currently logged account to another account. It has no parameters and no return values.
     **/


    



