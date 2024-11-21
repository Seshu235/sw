use std::net::TcpListener;
use std::thread::spawn;
use tungstenite::accept;

fn main() {
    let server = TcpListener::bind("127.0.0.1:9001").unwrap();
    println!("WebSocket server listening on ws://127.0.0.1:9001");

    for stream in server.incoming() {
        spawn(move || {
            let mut websocket = accept(stream.unwrap()).unwrap();
            loop {
                let msg = websocket.read_message().unwrap();

                // We don't want to send back ping/pong messages.
                if msg.is_binary() || msg.is_text() {
                    println!("Received: {}", msg);
                    let response = format!("Server received: {}", msg);
                    websocket.write_message(tungstenite::Message::Text(response)).unwrap();
                }
            }
        });
    }
}