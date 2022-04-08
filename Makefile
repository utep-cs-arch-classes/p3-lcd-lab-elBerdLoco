all:
	(cd timerLib; make install)
	(cd lcdLib; make install)
	(cd 1_shape_demo; make)
	(cd 2_button_demo; make)
	(cd 3_moving_shapes; make)
	(cd 4_wake_demo; make)

doc:
	rm -rf doxygen_docs
	doxygen Doxyfile
clean:
	(cd timerLib; make clean)
	(cd lcdLib; make clean)
	(cd 1_shape_demo; make clean)
	(cd 2_button_demo; make clean)
	(cd 3_moving_shapes; make clean)
	(cd 4_wake_demo; make clean)
	rm -rf lib h
	rm -rf doxygen_docs/*
