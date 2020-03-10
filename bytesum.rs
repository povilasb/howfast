use std::env;
use std::fs::File;
use std::io::Read;

const BUFF_SIZE: usize = 65535;

fn main() -> std::io::Result<()> {
    let file_path = match env::args().nth(1) {
        Some(file_path) => file_path,
        None => {
            println!("Usage: bytesumrs $file");
            return Ok(());
        }
    };

    let mut f = File::open(file_path)?;
    let mut data = [0u8; BUFF_SIZE];
    let mut s = 0u32;

    loop {
        let bytes_read = f.read(&mut data)?;
        if bytes_read == 0 {
            break;
        }

        for b in data[..bytes_read].iter() {
            s = (s + u32::from(*b)) % 255;
        }
    }

    println!("Sum % 255 = {}", s);

    Ok(())
}
