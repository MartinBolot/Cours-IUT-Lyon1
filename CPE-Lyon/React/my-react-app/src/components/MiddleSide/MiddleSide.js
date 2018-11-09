import React, { Component } from 'react';
import Part from "../Part/Part";

class MiddleSide extends Component {
  render() {
      return this.props.parts.map((part, index) => {
          return (
            <Part key={index} part={part}/>
          );
      });
  }
}

export default MiddleSide;
