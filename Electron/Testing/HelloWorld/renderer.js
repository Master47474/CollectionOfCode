const myNotification = new Notification("Title",  {
  body: "Notification from the renderer process"
})

myNotification.onclick = () => {
  console.log("notification Clicked")
}
