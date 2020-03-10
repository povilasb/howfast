src_dir ?= $(CURDIR)
image_tag := povilasb/howfast

image:
	docker build -t $(image_tag) .
.PHONY: image

container:
	docker run -i \
		-v $(src_dir):/root/howfast \
		-t $(image_tag) \
		bash
.PHONY: container

bytesumc: bytesum.c
	gcc -Ofast bytesum.c -o bytesumc

bytesumrs: bytesum.rs
	rustc -C opt-level=3 bytesum.rs -o bytesumrs
