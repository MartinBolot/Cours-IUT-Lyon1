import React, { Component } from 'react';
import Part from "../Part/Part";

class MiddleSide extends Component {
  constructor(props) {
    super(props);
    this.state = {
      parts: this.props.parts,
    }
  }
  render() {
      return this.state.parts.map((part, index) => {
          return (
            <Part key={index} part={part}/>
          );
      });
  }
}

export default MiddleSide;
