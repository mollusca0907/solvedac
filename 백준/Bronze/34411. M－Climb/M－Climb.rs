use std::io::{self, BufRead, Write};

fn main() {
    let mut ilock = io::stdin().lock();
    let mut olock = io::stdout().lock();

    let mut buf = String::new();

    ilock.read_line(&mut buf).expect("error");
    let n: usize = buf.trim().parse::<usize>().unwrap();
    buf.clear();

    ilock.read_line(&mut buf).expect("error");
    let m: usize = buf.trim().parse::<usize>().unwrap();
    buf.clear();

    ilock.read_line(&mut buf).expect("error");
    let _y: usize = buf.trim().parse::<usize>().unwrap();
    buf.clear();

    writeln!(olock, "{}", n * m).unwrap();
}
