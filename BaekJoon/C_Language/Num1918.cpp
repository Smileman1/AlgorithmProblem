#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int RESULT_STACK_SIZE = 100;
int POST_STACK_SIZE = 100;
int INPUT_STACK_SIZE = 100;
int TMP_STACK_SIZE = 100;

int* stackResult;
char* postStack;
char* inputStack;
char* tmpStack;

int resultTop = -1;
int postTop = -1;
int inputTop = -1;
int tmpTop = -1;

typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand }precedence;
int isp[] = { 0,19,12,12,13,13,13,0 };
int icp[] = { 20,19,12,12,13,13,13,0 };

void stackResult_full()
{
	RESULT_STACK_SIZE *= 2;
	stackResult = (int*)realloc(stackResult, RESULT_STACK_SIZE * sizeof(int));
}
int popResult()
{
	return *(stackResult + (resultTop--));
}
void pushResult(int a)
{
	if (resultTop >= RESULT_STACK_SIZE - 1)
	{
		stackResult_full();
	}
	*(stackResult + (++resultTop)) = a;
}

////////////////////////////////////////////////////////////////
void postStack_full()
{
	POST_STACK_SIZE *= 2;
	postStack = (char*)realloc(postStack, POST_STACK_SIZE * sizeof(char));
}
char popPost()
{
	return *(postStack + (postTop--));
}
void pushPost(char a)
{
	if (postTop >= POST_STACK_SIZE - 1)
	{
		postStack_full();
	}
	*(postStack + (++postTop)) = a;
}
//////////////////////////////////////////////////////////////////////
void inputStack_full()
{
	INPUT_STACK_SIZE *= 2;
	inputStack = (char*)realloc(inputStack, INPUT_STACK_SIZE * sizeof(char));
}
char popInput()
{
	return *(inputStack + (inputTop--));
}
void pushInput(char a)
{
	if (inputTop >= INPUT_STACK_SIZE - 1)
	{
		inputStack_full();
	}
	*(inputStack + (++inputTop)) = a;
}
////////////////////////////////////////////////////////////////////////
void tmpStack_full()
{
	TMP_STACK_SIZE *= 2;
	tmpStack = (char*)realloc(tmpStack, TMP_STACK_SIZE * sizeof(char));
}
char poptmp()
{
	return *(tmpStack + (tmpTop--));
}
void pushtmp(char a)
{
	if (tmpTop >= TMP_STACK_SIZE - 1)
	{
		tmpStack_full();
	}
	*(tmpStack + (++tmpTop)) = a;
}
///////////////////////////////////////////////////////////////////////




precedence getToken(char* symbol, int* n) {
	*symbol = postStack[(*n)++];
	switch (*symbol)
	{
	case '(':return lparen;
	case ')':return rparen;
	case '+':return plus;
	case '-':return minus;
	case '/':return divide;
	case '*':return times;
	case '%':return mod;
	case '\0':return eos;
	default:return operand;
	}
}

int eval(void) {
	precedence token;
	char symbol;
	int count = 1;
	int op1, op2;
	int n = 0;
	token = getToken(&symbol, &n);
	while (token != eos) {
		if (token == operand)
			pushResult(symbol - '0');
		else {
			op2 = popResult();
			op1 = popResult();
			switch (token)
			{
			case plus: pushResult(op1 + op2);
				printf("%d번째 연산:%d + %d\n", count++, op1, op2);
				break;
			case minus:pushResult(op1 - op2);
				printf("%d번째 연산:%d - %d\n", count++, op1, op2);
				break;
			case times:pushResult(op1 * op2);
				printf("%d번째 연산:%d * %d\n", count++, op1, op2);
				break;
			case divide:pushResult(op1 / op2);
				printf("%d번째 연산:%d / %d\n", count++, op1, op2);
				break;
			case mod:pushResult(op1 % op2);
				printf("%d번째 연산:%d %% %d\n", count++, op1, op2);
			}
		}
		token = getToken(&symbol, &n);
	}
	return popResult();
}

precedence getToken2(char* symbol, int* n) {
	*symbol = inputStack[(*n)++];
	switch (*symbol)
	{
	case '(':return lparen;
	case ')':return rparen;
	case '+':return plus;
	case '-':return minus;
	case '/':return divide;
	case '*':return times;
	case '%':return mod;
	case '\0':return eos;
	default:return operand;
	}
}
precedence getToken3(char* symbol) {
	switch (*symbol)
	{
	case '(':return lparen;
	case ')':return rparen;
	case '+':return plus;
	case '-':return minus;
	case '/':return divide;
	case '*':return times;
	case '%':return mod;
	case '\0':return eos;
	default:return operand;
	}
}

void postfix(void) {
	char symbol;
	precedence token, token2 = eos;
	int n = 0;
	int i = 1;
	tmpTop = 0;
	*(tmpStack) = '\0';
	for (token = getToken2(&symbol, &n); token != eos; token = getToken2(&symbol, &n))
	{
		if (token == operand)
			pushPost(symbol);
		else if (token == rparen)
		{
			while (*(tmpStack + tmpTop) != '(')
				pushPost(poptmp());
			poptmp();
		}
		else {
			while (isp[getToken3((tmpStack + tmpTop))] >= icp[token])
			{
				pushPost(poptmp());
			}
			pushtmp(symbol);
		}
		pushPost('\0');
		pushtmp('\0');
		i = 1;
		popPost();
		poptmp();
	}
	while (tmpTop != -1)
		pushPost(poptmp());
}
int main() {
	stackResult = (int*)malloc(sizeof(int) * 100);
	postStack = (char*)malloc(sizeof(char) * 100);
	inputStack = (char*)malloc(sizeof(char) * 100);
	tmpStack = (char*)malloc(sizeof(char) * 100);

	scanf("%s", inputStack);
	postfix();
	printf("%s", (postStack));

}