#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "utils/cmdline.h"
#include "utils/uartstdio.h"
#include "utils/ustdlib.h"
#include "driverlib/uart.h"
#include "driverlib/rom.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"
#include "inc/tm4c123gh6pm.h"


#define APP_INPUT_BUF_SIZE               128

static char g_cInput[APP_INPUT_BUF_SIZE];
uint32_t ui32PulseCounter1;
bool bFreeMotion1;
uint32_t ui32PulseCounter2;
bool bFreeMotion2;
uint32_t ui32PulseCounter3;
bool bFreeMotion3;
uint32_t ui32PulseCounter4;
bool bFreeMotion4;
uint32_t ui32PulseCounter5;
bool bFreeMotion5;
uint32_t ui32PulseCounter6;
bool bFreeMotion6;

int CMD_Joint1Start (int argc, char *argv[]) {
	bFreeMotion1 = true;
	TimerEnable(TIMER0_BASE, TIMER_A);
	return(0);
}

int CMD_Joint1Stop (int argc, char *argv[]) {
	TimerDisable(TIMER0_BASE, TIMER_A);
	return(0);
}

int CMD_Joint1Freq (int argc, char *argv[]) {
	uint32_t ui32Frequency;
	uint32_t ui32Period;

    if(argc == 2)
    {
        ui32Frequency = ustrtoul(argv[1], 0, 10);

        ui32Period=(SysCtlClockGet()/ui32Frequency)/2;
        TimerLoadSet(TIMER0_BASE, TIMER_A, ui32Period-1);
    }
	return(0);
}

int CMD_Joint1Dir (int argc, char *argv[]) {
	uint32_t ui32Direction;

    if(argc == 2)
    {
        ui32Direction = ustrtoul(argv[1], 0, 10);

        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, ui32Direction);
    }
	return(0);
}

int CMD_Joint1 (int argc, char *argv[]) {
	uint32_t ui32Frequency;
	uint32_t ui32Direction;
	uint32_t ui32Pulses;
	uint32_t ui32Period;

    if(argc == 4)
    {
        ui32Frequency = ustrtoul(argv[1], 0, 10);
        ui32Direction = ustrtoul(argv[2], 0, 10);
        ui32Pulses = ustrtoul(argv[3], 0, 10);

        ui32PulseCounter1 = ui32Pulses*2;

        bFreeMotion1 = false;

        ui32Period=(SysCtlClockGet()/ui32Frequency)/2;
        TimerLoadSet(TIMER0_BASE, TIMER_A, ui32Period-1);

        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, ui32Direction);

        TimerEnable(TIMER0_BASE, TIMER_A);
    }
	return(0);
}

int CMD_Joint2Start (int argc, char *argv[]) {
	bFreeMotion2 = true;
	TimerEnable(TIMER1_BASE, TIMER_A);
	return(0);
}

int CMD_Joint2Stop (int argc, char *argv[]) {
	TimerDisable(TIMER1_BASE, TIMER_A);
	return(0);
}

int CMD_Joint2Freq (int argc, char *argv[]) {
	uint32_t ui32Frequency;
	uint32_t ui32Period;

    if(argc == 2)
    {
        ui32Frequency = ustrtoul(argv[1], 0, 10);

        ui32Period=(SysCtlClockGet()/ui32Frequency)/2;
        TimerLoadSet(TIMER1_BASE, TIMER_A, ui32Period-1);
    }
	return(0);
}

int CMD_Joint2Dir (int argc, char *argv[]) {
	uint32_t ui32Direction;

    if(argc == 2)
    {
        ui32Direction = ustrtoul(argv[1], 0, 10);

        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, ui32Direction << 1);
    }
	return(0);
}

int CMD_Joint2 (int argc, char *argv[]) {
	uint32_t ui32Frequency;
	uint32_t ui32Direction;
	uint32_t ui32Pulses;
	uint32_t ui32Period;

    if(argc == 4)
    {
        ui32Frequency = ustrtoul(argv[1], 0, 10);
        ui32Direction = ustrtoul(argv[2], 0, 10);
        ui32Pulses = ustrtoul(argv[3], 0, 10);

        ui32PulseCounter2 = ui32Pulses*2;

        bFreeMotion2 = false;

        ui32Period=(SysCtlClockGet()/ui32Frequency)/2;
        TimerLoadSet(TIMER1_BASE, TIMER_A, ui32Period-1);

        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, ui32Direction << 1);

        TimerEnable(TIMER1_BASE, TIMER_A);
    }
	return(0);
}

int CMD_Joint3Start (int argc, char *argv[]) {
	bFreeMotion3 = true;
	TimerEnable(TIMER2_BASE, TIMER_A);
	return(0);
}

int CMD_Joint3Stop (int argc, char *argv[]) {
	TimerDisable(TIMER2_BASE, TIMER_A);
	return(0);
}

int CMD_Joint3Freq (int argc, char *argv[]) {
	uint32_t ui32Frequency;
	uint32_t ui32Period;

    if(argc == 2)
    {
        ui32Frequency = ustrtoul(argv[1], 0, 10);

        ui32Period=(SysCtlClockGet()/ui32Frequency)/2;
        TimerLoadSet(TIMER2_BASE, TIMER_A, ui32Period-1);
    }
	return(0);
}

int CMD_Joint3Dir (int argc, char *argv[]) {
	uint32_t ui32Direction;

    if(argc == 2)
    {
        ui32Direction = ustrtoul(argv[1], 0, 10);

        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, ui32Direction << 2);
    }
	return(0);
}

int CMD_Joint3 (int argc, char *argv[]) {
	uint32_t ui32Frequency;
	uint32_t ui32Direction;
	uint32_t ui32Pulses;
	uint32_t ui32Period;

    if(argc == 4)
    {
        ui32Frequency = ustrtoul(argv[1], 0, 10);
        ui32Direction = ustrtoul(argv[2], 0, 10);
        ui32Pulses = ustrtoul(argv[3], 0, 10);

        ui32PulseCounter3 = ui32Pulses*2;

        bFreeMotion3 = false;

        ui32Period=(SysCtlClockGet()/ui32Frequency)/2;
        TimerLoadSet(TIMER2_BASE, TIMER_A, ui32Period-1);

        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, ui32Direction << 2);

        TimerEnable(TIMER2_BASE, TIMER_A);
    }
	return(0);
}

int CMD_Joint4Start (int argc, char *argv[]) {
	bFreeMotion4 = true;
	TimerEnable(TIMER3_BASE, TIMER_A);
	return(0);
}

int CMD_Joint4Stop (int argc, char *argv[]) {
	TimerDisable(TIMER3_BASE, TIMER_A);
	return(0);
}

int CMD_Joint4Freq (int argc, char *argv[]) {
	uint32_t ui32Frequency;
	uint32_t ui32Period;

    if(argc == 2)
    {
        ui32Frequency = ustrtoul(argv[1], 0, 10);

        ui32Period=(SysCtlClockGet()/ui32Frequency)/2;
        TimerLoadSet(TIMER3_BASE, TIMER_A, ui32Period-1);
    }
	return(0);
}

int CMD_Joint4Dir (int argc, char *argv[]) {
	uint32_t ui32Direction;

    if(argc == 2)
    {
        ui32Direction = ustrtoul(argv[1], 0, 10);

        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, ui32Direction << 3);
    }
	return(0);
}

int CMD_Joint4 (int argc, char *argv[]) {
	uint32_t ui32Frequency;
	uint32_t ui32Direction;
	uint32_t ui32Pulses;
	uint32_t ui32Period;

    if(argc == 4)
    {
        ui32Frequency = ustrtoul(argv[1], 0, 10);
        ui32Direction = ustrtoul(argv[2], 0, 10);
        ui32Pulses = ustrtoul(argv[3], 0, 10);

        ui32PulseCounter4 = ui32Pulses*2;

        bFreeMotion4 = false;

        ui32Period=(SysCtlClockGet()/ui32Frequency)/2;
        TimerLoadSet(TIMER3_BASE, TIMER_A, ui32Period-1);

        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, ui32Direction << 3);

        TimerEnable(TIMER3_BASE, TIMER_A);
    }
	return(0);
}

int CMD_Joint5Start (int argc, char *argv[]) {
	bFreeMotion5 = true;
	TimerEnable(TIMER4_BASE, TIMER_A);
	return(0);
}

int CMD_Joint5Stop (int argc, char *argv[]) {
	TimerDisable(TIMER4_BASE, TIMER_A);
	return(0);
}

int CMD_Joint5Freq (int argc, char *argv[]) {
	uint32_t ui32Frequency;
	uint32_t ui32Period;

    if(argc == 2)
    {
        ui32Frequency = ustrtoul(argv[1], 0, 10);

        ui32Period=(SysCtlClockGet()/ui32Frequency)/2;
        TimerLoadSet(TIMER4_BASE, TIMER_A, ui32Period-1);
    }
	return(0);
}

int CMD_Joint5Dir (int argc, char *argv[]) {
	uint32_t ui32Direction;

    if(argc == 2)
    {
        ui32Direction = ustrtoul(argv[1], 0, 10);

        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, ui32Direction << 6);
    }
	return(0);
}

int CMD_Joint5 (int argc, char *argv[]) {
	uint32_t ui32Frequency;
	uint32_t ui32Direction;
	uint32_t ui32Pulses;
	uint32_t ui32Period;

    if(argc == 4)
    {
        ui32Frequency = ustrtoul(argv[1], 0, 10);
        ui32Direction = ustrtoul(argv[2], 0, 10);
        ui32Pulses = ustrtoul(argv[3], 0, 10);

        ui32PulseCounter5 = ui32Pulses*2;

        bFreeMotion5 = false;

        ui32Period=(SysCtlClockGet()/ui32Frequency)/2;
        TimerLoadSet(TIMER4_BASE, TIMER_A, ui32Period-1);

        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, ui32Direction << 6);

        TimerEnable(TIMER4_BASE, TIMER_A);
    }
	return(0);
}

int CMD_Joint6Start (int argc, char *argv[]) {
	bFreeMotion6 = true;
	TimerEnable(TIMER5_BASE, TIMER_A);
	return(0);
}

int CMD_Joint6Stop (int argc, char *argv[]) {
	TimerDisable(TIMER5_BASE, TIMER_A);
	return(0);
}

int CMD_Joint6Freq (int argc, char *argv[]) {
	uint32_t ui32Frequency;
	uint32_t ui32Period;

    if(argc == 2)
    {
        ui32Frequency = ustrtoul(argv[1], 0, 10);

        ui32Period=(SysCtlClockGet()/ui32Frequency)/2;
        TimerLoadSet(TIMER6_BASE, TIMER_A, ui32Period-1);
    }
	return(0);
}

int CMD_Joint6Dir (int argc, char *argv[]) {
	uint32_t ui32Direction;

    if(argc == 2)
    {
        ui32Direction = ustrtoul(argv[1], 0, 10);

        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7, ui32Direction << 7);
    }
	return(0);
}

int CMD_Joint6 (int argc, char *argv[]) {
	uint32_t ui32Frequency;
	uint32_t ui32Direction;
	uint32_t ui32Pulses;
	uint32_t ui32Period;

    if(argc == 4)
    {
        ui32Frequency = ustrtoul(argv[1], 0, 10);
        ui32Direction = ustrtoul(argv[2], 0, 10);
        ui32Pulses = ustrtoul(argv[3], 0, 10);

        ui32PulseCounter6 = ui32Pulses*2;

        bFreeMotion6 = false;

        ui32Period=(SysCtlClockGet()/ui32Frequency)/2;
        TimerLoadSet(TIMER5_BASE, TIMER_A, ui32Period-1);

        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7, ui32Direction << 7);

        TimerEnable(TIMER5_BASE, TIMER_A);
    }
	return(0);
}

int CMD_Help (int argc, char *argv[]) {
    int32_t i32Index;

    (void)argc;
    (void)argv;

    i32Index = 0;

    UARTprintf("\nAvailable Commands\n------------------\n\n");

    while(g_psCmdTable[i32Index].pcCmd)
    {
      UARTprintf("%17s %s\n", g_psCmdTable[i32Index].pcCmd,
                 g_psCmdTable[i32Index].pcHelp);
      i32Index++;
    }

    UARTprintf("\n");

    return (0);
}

tCmdLineEntry g_psCmdTable[]= {
	{"joint1_start",	CMD_Joint1Start,	" : Joint 1 start"},
	{"joint1_stop",		CMD_Joint1Stop,		" : Joint 1 emergency stop"},
	{"joint1_freq",		CMD_Joint1Freq,		" : Joint 1 frequency"},
	{"joint1_dir",		CMD_Joint1Dir,		" : Joint 1 direction"},
	{"joint1",			CMD_Joint1,			" : Joint 1 move setup 'freq dir pulses'"},
	{"joint2_start",	CMD_Joint2Start,	" : Joint 2 start"},
	{"joint2_stop",		CMD_Joint2Stop,		" : Joint 2 emergency stop"},
	{"joint2_freq",		CMD_Joint2Freq,		" : Joint 2 frequency"},
	{"joint2_dir",		CMD_Joint2Dir,		" : Joint 2 direction"},
	{"joint2",			CMD_Joint2,			" : Joint 2 move setup 'freq dir pulses'"},
	{"joint3_start",	CMD_Joint3Start,	" : Joint 3 start"},
	{"joint3_stop",		CMD_Joint3Stop,		" : Joint 3 emergency stop"},
	{"joint3_freq",		CMD_Joint3Freq,		" : Joint 3 frequency"},
	{"joint3_dir",		CMD_Joint3Dir,		" : Joint 3 direction"},
	{"joint3",			CMD_Joint3,			" : Joint 3 move setup 'freq dir pulses'"},
	{"joint4_start",	CMD_Joint4Start,	" : Joint 1 start"},
	{"joint4_stop",		CMD_Joint4Stop,		" : Joint 4 emergency stop"},
	{"joint4_freq",		CMD_Joint4Freq,		" : Joint 4 frequency"},
	{"joint4_dir",		CMD_Joint4Dir,		" : Joint 4 direction"},
	{"joint4",			CMD_Joint4,			" : Joint 4 move setup 'freq dir pulses'"},
	{"joint5_start",	CMD_Joint5Start,	" : Joint 5 start"},
	{"joint5_stop",		CMD_Joint5Stop,		" : Joint 5 emergency stop"},
	{"joint5_freq",		CMD_Joint5Freq,		" : Joint 5 frequency"},
	{"joint5_dir",		CMD_Joint5Dir,		" : Joint 5 direction"},
	{"joint5",			CMD_Joint5,			" : Joint 5 move setup 'freq dir pulses'"},
	{"joint6_start",	CMD_Joint6Start,	" : Joint 6 start"},
	{"joint6_stop",		CMD_Joint6Stop,		" : Joint 6 emergency stop"},
	{"joint6_freq",		CMD_Joint6Freq,		" : Joint 6 frequency"},
	{"joint6_dir",		CMD_Joint6Dir,		" : Joint 6 direction"},
	{"joint6",			CMD_Joint6,			" : Joint 6 move setup 'freq dir pulses'"},
	{"help",			CMD_Help,			" : Aplication Help"},
	{0, 0, 0}
};

void main(void) {
	int32_t i32CommandStatus;
	uint32_t ui32Period;

	//clock setup
	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

	//porte setup
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
	GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);

	//portc setup
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
	GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, 0);

	//portd setup
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_6|GPIO_PIN_7);
	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_6|GPIO_PIN_7, 0);

	//timer 0 setup
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
	TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
	//timer 1 setup
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
	TimerConfigure(TIMER1_BASE, TIMER_CFG_PERIODIC);
	//timer 2 setup
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
	TimerConfigure(TIMER2_BASE, TIMER_CFG_PERIODIC);
	//timer 3 setup
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER3);
	TimerConfigure(TIMER3_BASE, TIMER_CFG_PERIODIC);
	//timer 4 setup
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER4);
	TimerConfigure(TIMER4_BASE, TIMER_CFG_PERIODIC);
	//timer 5 setup
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER5);
	TimerConfigure(TIMER5_BASE, TIMER_CFG_PERIODIC);
	
	ui32Period=(SysCtlClockGet()/5)/2;
	TimerLoadSet(TIMER0_BASE, TIMER_A, ui32Period-1);
	TimerLoadSet(TIMER1_BASE, TIMER_A, ui32Period-1);
	TimerLoadSet(TIMER2_BASE, TIMER_A, ui32Period-1);
	TimerLoadSet(TIMER3_BASE, TIMER_A, ui32Period-1);
	TimerLoadSet(TIMER4_BASE, TIMER_A, ui32Period-1);
	TimerLoadSet(TIMER5_BASE, TIMER_A, ui32Period-1);

	//interrupts enable
	IntEnable(INT_TIMER0A);
	IntEnable(INT_TIMER1A);
	IntEnable(INT_TIMER2A);
	IntEnable(INT_TIMER3A);
	IntEnable(INT_TIMER4A);
	IntEnable(INT_TIMER5A);
	TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
	TimerIntEnable(TIMER1_BASE, TIMER_TIMA_TIMEOUT);
	TimerIntEnable(TIMER2_BASE, TIMER_TIMA_TIMEOUT);
	TimerIntEnable(TIMER3_BASE, TIMER_TIMA_TIMEOUT);
	TimerIntEnable(TIMER4_BASE, TIMER_TIMA_TIMEOUT);
	TimerIntEnable(TIMER5_BASE, TIMER_TIMA_TIMEOUT);
	IntMasterEnable();

    //UART setup
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    ROM_GPIOPinConfigure(GPIO_PA0_U0RX);
    ROM_GPIOPinConfigure(GPIO_PA1_U0TX);
    ROM_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);

    UARTStdioConfig(0, 115200, 16000000);

	// Print the header
	UARTprintf("Welcome to the Tiva C Series TM4C123G LaunchPad!\n");
    UARTprintf("Type 'help' for a list of commands\n");
    UARTprintf("> ");


    while(1) {
		UARTprintf("\n>");

		// Peek to see if a full command is ready for processing
		while(UARTPeek('\r') == -1);

		// a '\r' was detected get the line of text from the user.
		UARTgets(g_cInput,sizeof(g_cInput));

		// Pass the line from the user to the command processor.
		// It will be parsed and valid commands executed.
		i32CommandStatus = CmdLineProcess(g_cInput);

		// Handle the case of bad command.
		if(i32CommandStatus == CMDLINE_BAD_CMD) UARTprintf("Bad command!\n");

		// Handle the case of too many arguments.
		else if(i32CommandStatus == CMDLINE_TOO_MANY_ARGS) UARTprintf("Too many arguments for command processor!\n");
	}
}

void Timer0IntHandler(void) {
	//clear the timer interrupt
	TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

	//Generate the pulses
	if (GPIOPinRead(GPIO_PORTE_BASE, GPIO_PIN_1)) GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0);
	else GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 2);

	if (!bFreeMotion1) {
		ui32PulseCounter1--;
		if (ui32PulseCounter1 == 0) TimerDisable(TIMER0_BASE, TIMER_A);
	}
}

void Timer1IntHandler(void) {
	//clear the timer interrupt
	TimerIntClear(TIMER1_BASE, TIMER_TIMA_TIMEOUT);

	//Generate the pulses
	if (GPIOPinRead(GPIO_PORTE_BASE, GPIO_PIN_2)) GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0);
	else GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 4);

	if (!bFreeMotion2) {
		ui32PulseCounter2--;
		if (ui32PulseCounter2 == 0) TimerDisable(TIMER1_BASE, TIMER_A);
	}
}

void Timer2IntHandler(void) {
	//clear the timer interrupt
	TimerIntClear(TIMER2_BASE, TIMER_TIMA_TIMEOUT);

	//Generate the pulses
	if (GPIOPinRead(GPIO_PORTE_BASE, GPIO_PIN_3)) GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0);
	else GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 8);

	if (!bFreeMotion3) {
		ui32PulseCounter3--;
		if (ui32PulseCounter3 == 0) TimerDisable(TIMER2_BASE, TIMER_A);
	}
}

void Timer3IntHandler(void) {
	//clear the timer interrupt
	TimerIntClear(TIMER3_BASE, TIMER_TIMA_TIMEOUT);

	//Generate the pulses
	if (GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_5)) GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0);
	else GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 32);

	if (!bFreeMotion4) {
		ui32PulseCounter4--;
		if (ui32PulseCounter4 == 0) TimerDisable(TIMER3_BASE, TIMER_A);
	}
}

void Timer4IntHandler(void) {
	//clear the timer interrupt
	TimerIntClear(TIMER4_BASE, TIMER_TIMA_TIMEOUT);

	//Generate the pulses
	if (GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_6)) GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0);
	else GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 64);

	if (!bFreeMotion5) {
		ui32PulseCounter5--;
		if (ui32PulseCounter5 == 0) TimerDisable(TIMER4_BASE, TIMER_A);
	}
}

void Timer5IntHandler(void) {
	//clear the timer interrupt
	TimerIntClear(TIMER5_BASE, TIMER_TIMA_TIMEOUT);

	//Generate the pulses
	if (GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_7)) GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0);
	else GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 128);

	if (!bFreeMotion6) {
		ui32PulseCounter6--;
		if (ui32PulseCounter6 == 0) TimerDisable(TIMER5_BASE, TIMER_A);
	}
}
