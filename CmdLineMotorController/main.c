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

	//portd setup
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2);
	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2, 0);

	//timer 0 setup
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
	TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
	//timer 1 setup
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
	TimerConfigure(TIMER1_BASE, TIMER_CFG_PERIODIC);
	//timer 2 setup
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
	TimerConfigure(TIMER2_BASE, TIMER_CFG_PERIODIC);
	
	ui32Period=(SysCtlClockGet()/5)/2;
	TimerLoadSet(TIMER0_BASE, TIMER_A, ui32Period-1);
	TimerLoadSet(TIMER1_BASE, TIMER_A, ui32Period-1);
	TimerLoadSet(TIMER2_BASE, TIMER_A, ui32Period-1);

	//interrupts enable
	IntEnable(INT_TIMER0A);
	IntEnable(INT_TIMER1A);
	IntEnable(INT_TIMER2A);
	TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
	TimerIntEnable(TIMER1_BASE, TIMER_TIMA_TIMEOUT);
	TimerIntEnable(TIMER2_BASE, TIMER_TIMA_TIMEOUT);
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
