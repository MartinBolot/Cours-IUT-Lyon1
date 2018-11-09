import React, { Component } from 'react';
import Part from "../Part/Part";

class MiddleSide extends Component {
  render() {
    if(this.props.parts) {
      return this.props.parts.map((part, index) => {
          return (
            <Part
              key={index}
              part={part}
              selected={this.props.selectedPartId === part.id}
            />
          );
      });
    }
    else {
      return( <div>No robot selected</div> );
    }
  }
}

export default MiddleSide;
