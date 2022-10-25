
#include	"../include/philo.h"

/**
 * @brief returns the current timestamp from the first call of the funktion
 * 
 * @param timestamp the struct where the seconds and nanoseconds are stored
 */
void	get_time_stamp(struct timeval *timestamp)
{
	static int				first_call = 1;
	static struct timeval	start_time;

	if (first_call == 1)
	{
		gettimeofday(&start_time, NULL);
		first_call = 0;
		memset(timestamp, 0, sizeof(struct timeval));
		return ;
	}
	gettimeofday(timestamp, NULL);
	timestamp->tv_sec -= start_time.tv_sec;
	timestamp->tv_usec -= start_time.tv_usec;
	if (timestamp->tv_usec < 0)
	{
		timestamp->tv_sec--;
		timestamp->tv_usec += 1000000;
	}
}


/**
 * @brief 
 *  prints the current timestamp in milisec
 *  => 23132.123 ms after is nanosec
 *  first call should return 0.000 ms
 */
void	print_timestamp(void)
{
	struct timeval	timestamp;

	get_time_stamp(&timestamp);
	if (timestamp.tv_sec > 0)
	{
		printf("%li", timestamp.tv_sec);
		if (timestamp.tv_usec / 1000 < 10)
			printf("00");
		else if (timestamp.tv_usec / 1000 < 100)
			printf("0");
	}
	printf("%.f ms", ((double)timestamp.tv_usec / 1000));
}
