import React, { Component } from 'react';
import './App.css';

class App extends Component {
  constructor(props) {
    super(props);
    this.state = {
      title: this.props.title,
      hoverTitleCount: 0
    };
    this.handleChangeTitle = this.handleChangeTitle.bind(this);
    this.handleHoverTitle = this.handleHoverTitle.bind(this);
  }

  handleChangeTitle(e) {
    this.setState({title: e.target.value});
  }

  handleHoverTitle(e) {
    this.setState({hoverTitleCount: this.state.hoverTitleCount+1});
  }

  render() {
    return (
      <div className="App">
        <h1 onMouseEnter={this.handleHoverTitle}>
          This is my first react component
          <span> {this.state.hoverTitleCount}</span>
        </h1>
        <label htmlFor="labelInput">Title</label>
        <input
          type="text"
          id="titleInput"
          onChange={this.handleChangeTitle}
          value={this.state.title}
        />
        <h3>{this.state.title}</h3>
      </div>
    );
  }
}

export default App;
