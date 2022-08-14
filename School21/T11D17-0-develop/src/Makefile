CC=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD_PATH=../build/
SOURSES=dmanager_module.c
H=door_struct.h
EXE_1=Quest_1

STAGE_1=door_struct

all: $(STAGE_1)
clean:
	find $(BUILD_PATH) -name 'Q*' -delete
rebuild: clean all

$(STAGE_1):
	$(CC) $(CFLAGS) $(SOURSES) -o $(BUILD_PATH)$(EXE_1)

git: clean
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
	cppcheck --enable=all --suppress=missingIncludeSystem $(SOURSES)
	@echo
	@echo ===STYLE TEST===
	@echo
	python3 ../materials/linters/cpplint.py --extensions=c $(SOURSES) $(H)
	@echo
	@echo ===LEAKS TEST===
	@echo
	leaks --atExit -- $(BUILD_PATH)$(EXE_1)