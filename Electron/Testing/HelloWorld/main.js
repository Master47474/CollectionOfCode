const {app, BrowserWindow, Notification } = require('electron');
const path = require('path')



function createWindow (){
  const win = new BrowserWindow({
    width: 800,
    height: 600,
    webPreferences: {
      nodeIntegration: true
    }
  })

  win.loadFile('index.html');
  // progress bars
  win.setProgressBar(0.5)
  // end Progress bars

  //custom thumbnail toolbar

  //win.setThumbarButtons([]) remove all buttons
  //End custom thumbnail
}


app.on('window-all-closed', () => {
  if(process.platform !== 'darwin'){
    app.quit();
  }
});

app.on('activate', () => {
  if (BrowserWindow.getAllWindows().length === 0){
    createWindow();
  }
});

// Notifications

function showNotification () {
  const notification = {
    title: "Basic Notification",
    body: "Notification from the main process"
  }
  new Notification(notification).show()
}

// End notifications


// Recent Documents
app.addRecentDocument('/Users/Marcus/Desktop/Resume_Marcus.docx')
// enable permissions

// End recent Documents



app.whenReady().then(createWindow).then(showNotification)
