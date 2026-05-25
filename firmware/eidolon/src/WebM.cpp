#include <WebServer.h>
#include "MEDIA.h"
#include "ImageRender.h"
#include "LittleFS.h"


WebServer* Web::server = nullptr;
bool Web::initialized = false;


bool Web::init() {
    if (initialized) {
        return true;
    }
    server = new WebServer(80);
    server->on("/", HTTP_GET, handleRoot);
    server->on("/files", HTTP_GET, handleFiles);
    server->on("/oled", HTTP_GET, handleOled);
    server->on("/delete", HTTP_GET, handleDelete);
    server->on("/upload", HTTP_POST, handleUpload);
    server->begin();
    initialized = true;
    return true;
}

void Web::handle() {
    if (initialized) {
        server->handleClient();
    }
}


void Web::stop() {
    if (initialized) {
        server->stop();
        initialized = false;
    }
}

void Web::handleRoot() {
    string html = R"(
    <!DOCTYPE html>
    <html>
    <head>
        <title>Eidolon</title>
    </head>
    <body>
        <div class='container'>
            <h1>Eidolon</h1>
            <div class='control'>
                <h2> Upload </h2>
                <input type='file' id='file'>
                <button onClick='handleUpload()' id='upload'>Upload</button>
            </div>
            <div class='control'>
                <h2> Playback </h2>
                <button onClick='nextMedia()'>Next</button>
                <button onClick='prevMedia()'>Next</button>
            </div>
        </div>
        <script>
            function handleUpload() {
                const file = document.getElementById('file').files[0];
                const formData = new FormData();
                formData.append('file', file);
                fetch('/upload', {
                    method: 'POST',
                    body: formData
                }).then(response => {
                    if (response.ok) {
                        location.reload(true);
                    } else {
                        alert('File upload failed');
                    }
                });
            }
                function nextMedia() {
                    fetch('/next', { method: 'POST' }).then(response => {
                        if (response.ok) {
                            location.reload(true);
                        } else {
                            alert('Failed to load next media');
                        }
                    });
                }
                function prevMedia() {
                    fetch('/prev', { method: 'POST' }).then(response => {
                        if (response.ok) {
                            location.reload(true);
                        } else {
                            alert('Failed to load next media');
                        }
                    });
                }
            </script>
    </body>
    </html>
    )";
    server->send(200, "text/html", html);
};

