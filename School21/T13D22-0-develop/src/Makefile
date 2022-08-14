C=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD_PATH=../build/
SOURCES:=$(shell find . -name 'c*.c')
H:=$(shell find . -name 'c*.h')
EXE_1=cipher
STAGE_1=cipher

all: $(STAGE_1)
clean: 
	find $(BUILD_PATH) -name 'c*' -delete

rebuild: clean all

$(STAGE_1):
	$(CC) $(CFLAGS) $(SOURCES) -o $(BUILD_PATH)$(EXE_1)

push: clean
	@echo
	@echo ===GIT STATUS===
	@echo
	git status
	git add .
	@echo
	@echo ===GIT COMMIT===
	@echo
	git commit -m "$(EXE_1)"
	@echo
	@echo ===GIT PUSH===
	@echo
	git push origin develop

init:
	cp ../materials/linters/CPPLINT.cfg ./
	git checkout -b develop


check:
	@echo
	@echo ===CPPCHECK===
	@echo
	cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCES)
	clear
	@echo
	@echo ===STYLE TEST===
	@echo
	python3 ../materials/linters/cpplint.py --extensions=c $(SOURCES) $(H)
	clear
	@echo
	@echo ===LEAKS TEST===
	@echo
	leaks --atExit -- $(BUILD_PATH)$(EXE_1)

clear: clean
	clear

play:
	$(BUILD_PATH)$(EXE_1)