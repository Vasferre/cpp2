NAME = bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -Iincludes -std=c++98
OBJS_FOLDER = base
VPATH = srcs/
RM = rm -rf

OBJS = ${SRCS:%.cpp=${OBJS_FOLDER}/%.o}
SRCS =	main.cpp\
		AForm.cpp\
		PresidentialPardonForm.cpp\
		RobotmyRequestForm.cpp\
		ShrubberyCreationForm.cpp\
		Bureaucrat.cpp\
		Intern.cpp

${NAME}: ${OBJS_FOLDER} ${OBJS}
	${CXX} ${OBJS} -o ${NAME}

${OBJS_FOLDER}:
	mkdir -p base

${OBJS_FOLDER}/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	${RM} ${OBJS_FOLDER}

fclean: clean
	${RM} ${NAME}

all : ${NAME}

re: fclean all

.PHONY: ${NAME} fclean clean all re

.SILENT: