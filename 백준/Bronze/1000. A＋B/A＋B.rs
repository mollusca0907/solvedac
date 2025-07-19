use std::io::{self, BufRead, Write};

fn main() {
    let mut buf = String::new();
    io::stdin().lock().read_line(&mut buf).expect("input error");

    let input: Vec<String> = buf.split(" ").map(|s| s.to_owned()).collect();
    let a = input[0].trim().parse::<usize>().unwrap();
    let b = input[1].trim().parse::<usize>().unwrap();

    let mut olock = std::io::stdout().lock();
    writeln!(olock, "{}", a + b).unwrap();
}
