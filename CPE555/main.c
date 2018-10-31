/*
 * CPE-555 Real-Time and Embedded Systems
 * Stevens Institute of Technology
 * Fall 2017
 *
 * Homework 4
 *
 * Name: Joseph Puciloski
 */
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/* count and Queue are global so they can be used by all tasks */
unsigned int globalCount;
QueueHandle_t numberQueue;

/* Task Definitions */
void TxTask1 () {
	for(;;){
		/*push globalCount to Queue*/
		xQueueSend(numberQueue, &globalCount, (TickType_t) 10);

		/*Protect printf, print globalCount value, increment count and delay 500 ms*/
		taskENTER_CRITICAL();
		printf("globalCount value: %u \n", (globalCount++));
		vTaskDelay(500 / portTICK_RATE_MS);
		taskEXIT_CRITICAL();
	}
}
void TxTask2 () {
	for(;;){
		/*push globalCount to Queue*/
		xQueueSend(numberQueue, &globalCount, (TickType_t) 10);

		/*Protect printf, print globalCount value, increment count and delay 500 ms*/
		taskENTER_CRITICAL();
		printf("globalCount value: %u \n", (globalCount++));
		vTaskDelay(500 / portTICK_RATE_MS);
		taskEXIT_CRITICAL();
	}
}
void RxTask () {
	unsigned int receiveFromQueue;
	for(;;){
		if(xQueueReceive(numberQueue, &receiveFromQueue, (TickType_t) 10))
			printf("From Queue: %u\n" , receiveFromQueue);
	}
}

/* main application code */
int main( void )
{
	/* set STDOUT to be non-buffered to that printf() messages display immediately */
	setbuf(stdout, NULL);

	/*Initialize Queue*/
	numberQueue = xQueueCreate(10, sizeof(unsigned int));

	/* Check the queue to make sure it was initialized properly*/
	if(numberQueue == NULL){
		printf("Something went wrong");
	}
	/* Create Tasks */
	xTaskCreate (TxTask1, "Send to Queue 1", 1000, NULL, 1, NULL);
	xTaskCreate (TxTask2, "Send to Queue 2", 1000, NULL, 1, NULL);
	xTaskCreate (RxTask, "Receive From Queue", 1000, NULL, 1, NULL);

	/* Begin the simulation */
	vTaskStartScheduler();

	/*If the program executes this print statement there's most likely something wrong.*/
	printf("Error\n");
	return 0;
}



