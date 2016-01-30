##
## Makefile for  in /home/soidik_d/Semestre_05/cpp/rtype
## 
## Made by SOIDIKI Djamil
## Login   <soidik_d@epitech.net>
## 
## Started on  Thu Nov 19 17:04:53 2015 SOIDIKI Djamil
## Last update Fri Dec 25 13:36:45 2015 SOIDIKI Djamil
##

PATH_SOURCES	=	sources/

PATH_INCLUDES	=	includes/

PATH_MODULES	=	modules/

NAME		=	rtype

SRCS		=	$(PATH_SOURCES)Main.cpp \
			$(PATH_MODULES)debug/Debug.cpp \
			$(PATH_MODULES)exception/Exception.cpp \
			$(PATH_MODULES)network/USocket.cpp \
			$(PATH_MODULES)network/UExchange.cpp \
			$(PATH_MODULES)network/ResolveIP.cpp \
			$(PATH_MODULES)network/Packet.cpp \
			$(PATH_MODULES)thread/UThread.cpp \
			$(PATH_MODULES)thread/UMutex.cpp \
			$(PATH_MODULES)thread/UCondition.cpp \
			$(PATH_MODULES)thread/Pool.cpp \
			$(PATH_SOURCES)NetworkHandler.cpp \
			$(PATH_SOURCES)Server.cpp \
			$(PATH_SOURCES)Client.cpp \
			$(PATH_MODULES)protocol/Protocol.cpp \

OBJS		=	$(SRCS:.cpp=.o)

TEMP		=	$(PATH_SOURCES)*~ $(PATH_INCLUDES)*~ $(PATH_MODULES)*~ *~ $(PATH_MODULES)debug/*~ $(PATH_MODULES)network/*~ $(PATH_MODULES)exception/*~ $(PATH_MODULES)thread/*~ $(PATH_MODULES)protocol/*~ 

CXXFLAGS 	=	-Wall -Wextra -Werror -std=c++11

all:			$(NAME)

$(NAME):		$(OBJS)
			g++ -o $(NAME) $(OBJS) -lpthread

clean:
			rm -f $(OBJS) $(TEMP)

fclean:			clean
			rm -f $(NAME)

re:			fclean all

norm:			re
			rm -f $(OBJS)
