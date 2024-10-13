Libs = -pthread -lm

BuildDeadLock: ./growth_simulation_deadlock.c
	echo "Building...\n"
	gcc ./growth_simulation_deadlock.c ${Libs} -o growth_simulation_deadlock
	echo "Ready"

RunDeadLock: BuildDeadLock
	echo "Start run"
	./growth_simulation_deadlock

BuildFix: ./growth_simulation_fix.c
	echo "Building...\n"
	gcc ./growth_simulation_fix.c ${Libs} -o growth_simulation_fix
	echo "Ready"

RunFix: BuildFix
	echo "Start run"
	./growth_simulation_fix
