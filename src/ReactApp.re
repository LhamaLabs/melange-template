module App = {
  [@react.component]
  let make = () => {
    let (name, setName) = React.useState(() => World.name);

    <div>
      {[
        "Hello, " ++ name ++ "!"
      ]
      ->Belt.List.map(greeting => <h1 key={greeting}> greeting->React.string </h1>)
      ->Belt.List.toArray
      ->React.array}

      <label style=(ReactDOM.Style.make(~paddingRight="5px", ()))>{React.string("Name:")}</label>
      <input
        type_="text"
        value={name}
        onChange={event => {
          let newName = React.Event.Form.target(event)##value;
          setName(_ => newName);
        }}
        placeholder="Enter a name"
      />
    </div>
  };
};

switch (ReactDOM.querySelector("#root")) {
| Some(element) =>
  let root = ReactDOM.Client.createRoot(element);
  ReactDOM.Client.render(root, <App />);
| None =>
  Js.Console.error("Failed to start React: couldn't find the #root element")
};
