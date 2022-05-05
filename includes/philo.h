/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:21:52 by glaverdu          #+#    #+#             */
/*   Updated: 2021/10/30 11:42:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
# include <unistd.h>

# define SIM_ERROR "ERROR: error encountered during simulation\n" 
# define ARG_ERROR "ERROR: invalid / too many / too few arguments\n"
# define LEFT_FORK 'l'
# define RIGHT_FORK 'r'
# define THINK " is thinking\n" 
# define EAT " is eating\n" 
# define SLEEP " is sleeping\n" 
# define TAKE_FORK " has taken a fork\n" 
# define DEAD " died\n" 

typedef struct s_param
{
	int		num_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		times_must_eat;
	int		start_time;
}				t_param;

typedef struct s_philo
{
	int				pos;
	int				alive;
	int				t_last_ate;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				t_must_eat;
	int				start_time;
	int				num_of_philo;
	pthread_t		id;
	pthread_t		death_watch_id;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*died_lock;
	pthread_mutex_t	*ate_lock;
	pthread_mutex_t	*must_eat_lock;
	int				*someone_died;
}				t_philo;

typedef struct s_threads_data
{
	pthread_mutex_t	print_lock;
	pthread_mutex_t	died_lock;
	pthread_mutex_t	ate_lock;
	pthread_mutex_t	must_eat_lock;
	pthread_mutex_t	*fork;
	t_philo			**philos;
	int				someone_died;
	int				num_of_philos;
}				t_threads_data;

/*check args*/
int			arguments_are_valid(char **args, int nb_args);

/*thread routine/*/
void		*life_of_philo(void *data);
void		*life_of_1_philo(void *data);

/*inits*/
int			init_mutexes(t_threads_data *threads, t_param *param);
int			init_parameters(int argc, char **args, t_param *param);
int			init_philo(t_threads_data *threads, t_param *param);

/*philo actions*/
void		death_watch(t_threads_data *d);;
void		thinking(t_philo *philo);
void		sleeping(t_philo *philo);
void		get_fork(t_philo *philo, char fork_side);
void		put_fork_down(t_philo *philo, char fork_side);
void		eating(t_philo *philo);
void		someone_died(t_threads_data *threads);

/*help functions*/
long long	ft_atol(char *str, int *error);
int			ft_lite_atoi(char *s);
int			is_digit(char character);
int			is_within_int_range(long long number);
void		ft_putstr(char *string);
void		ft_putnbr(int nbr);
int			get_time_in_ms(void);
void		ms_sleep(int sleep_time);
void		print_philo_status(char *status, int time, int philo_nbr);	
int			philo_is_full(t_philo *philo);
int			check_if_philo_died(t_philo *philo);

/*exit*/
void		threads_cleaning_wrapper(t_threads_data *threads, t_param *param);
#endif
